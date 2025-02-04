#include "PreCompile.h"
#include "Inventory.h"

#include <EngineCore/ImageWidget.h>

#include "GlobalVar.h"


UInventory::UInventory()
{
}

UInventory::~UInventory()
{
}

void UInventory::Tick(float _DeltaTime)
{
	UImageWidget::Tick(_DeltaTime);
}

//void UInventory::SlotInit()
//{
//	// 2D 벡터 크기 조정
//	AllSlots.resize(InvenSize.Y); // Y(행) 크기 설정
//
//	int UnlockedCount = 0; // Unlock된 슬롯 개수를 세기 위한 변수
//	AHUD* HUD = GetWorld()->GetHUD<AHUD>(); // 현재 HUD 가져오기
//
//	if (HUD == nullptr)
//	{
//		MSGASSERT("HUD를 찾을 수 없습니다.");
//		return;
//	}
//
//	for (int y = 0; y < InvenSize.Y; ++y)
//	{
//		AllSlots[y].resize(InvenSize.X, nullptr); // nullptr로 초기화
//
//		for (int x = 0; x < InvenSize.X; ++x)
//		{
//			// HUD를 통해 새로운 슬롯 생성
//			ASlot* SlotWidget = HUD->CreateWidget<ASlot>(0, "SlotWidget").get();
//
//			if (SlotWidget == nullptr)
//			{
//				MSGASSERT("슬롯 위젯 생성 실패!");
//				continue;
//			}
//
//			// 벡터에 포인터 저장
//			AllSlots[y][x] = SlotWidget;
//
//			// 잠금 여부 설정
//			if (UnlockedCount < OpenSlot)
//			{
//				SlotWidget->IsLocked = false; // Unlock
//			}
//			else
//			{
//				SlotWidget->IsLocked = true; // Lock
//			}
//
//			// `IsLocked` 상태에 따라 텍스처 설정
//			if (SlotWidget->IsLocked)
//			{
//				SlotWidget->SetTexture("Inventory_SlotLock.png", true, ScaleRatio);
//			}
//			else
//			{
//				SlotWidget->SetTexture("Inventory_Slot #1184.png", true, ScaleRatio);
//			}
//
//			++UnlockedCount;
//		}
//	}
//}

void UInventory::SlotInit()
{
    // 2D 벡터 크기 조정
    AllSlots.resize(InvenSize.Y); // Y(행) 크기 설정

    int UnlockedCount = 0; // Unlock된 슬롯 개수를 세기 위한 변수
    AHUD* HUD = GetWorld()->GetHUD<AHUD>(); // 현재 HUD 가져오기

    if (HUD == nullptr)
    {
        MSGASSERT("HUD를 찾을 수 없습니다.");
        return;
    }

    // 인벤토리의 위치와 크기 반영
    FVector InventorySize = INVENTORY_Base * 0.94f; // 인벤토리 크기 조절
    FVector StartPosition = { INVENTORY_Pos.X - (InventorySize.X * ScaleRatio * 0.5f) + (InventorySize.X * ScaleRatio / (InvenSize.X * 2)), (InventorySize.Y * ScaleRatio) * 0.5f - (InventorySize.Y * ScaleRatio / (InvenSize.Y * 2)) };  // 기본 인벤토리 위치

    // 슬롯 간 간격을 인벤토리 크기에 맞게 자동 조정
    float SlotSpacingX = InventorySize.X / static_cast<float>(InvenSize.X) * ScaleRatio /** 0.8f*/ ;
    float SlotSpacingY = -InventorySize.Y / static_cast<float>(InvenSize.Y) * ScaleRatio /** 0.9f*/ ;

    for (int y = 0; y < InvenSize.Y; ++y)
    {
        AllSlots[y].resize(InvenSize.X, nullptr); // nullptr로 초기화

        for (int x = 0; x < InvenSize.X; ++x)
        {
            // HUD를 통해 새로운 슬롯 생성
            ASlot* SlotWidget = HUD->CreateWidget<ASlot>(0, "SlotWidget").get();

            if (SlotWidget == nullptr)
            {
                MSGASSERT("슬롯 위젯 생성 실패!");
                continue;
            }

            // 벡터에 포인터 저장
            AllSlots[y][x] = SlotWidget;

            // 잠금 여부 설정
            if (UnlockedCount < OpenSlot)
            {
                SlotWidget->IsLocked = false; // Unlock
            }
            else
            {
                SlotWidget->IsLocked = true; // Lock
            }

            // `IsLocked` 상태에 따라 텍스처 설정
            if (SlotWidget->IsLocked)
            {
                SlotWidget->SetTexture("Inventory_SlotLock.png", true, ScaleRatio);
            }
            else
            {
                SlotWidget->SetTexture("Inventory_Slot #1184.png", true, ScaleRatio);
            }

            // 슬롯 위치 계산 후 설정
            FVector SlotPosition = StartPosition + FVector(x * SlotSpacingX, y * SlotSpacingY, 0.0f);
            SlotWidget->SetWorldLocation(SlotPosition);

            ++UnlockedCount;
        }
    }
}
