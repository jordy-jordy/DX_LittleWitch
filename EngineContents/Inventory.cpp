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
//	// 2D ���� ũ�� ����
//	AllSlots.resize(InvenSize.Y); // Y(��) ũ�� ����
//
//	int UnlockedCount = 0; // Unlock�� ���� ������ ���� ���� ����
//	AHUD* HUD = GetWorld()->GetHUD<AHUD>(); // ���� HUD ��������
//
//	if (HUD == nullptr)
//	{
//		MSGASSERT("HUD�� ã�� �� �����ϴ�.");
//		return;
//	}
//
//	for (int y = 0; y < InvenSize.Y; ++y)
//	{
//		AllSlots[y].resize(InvenSize.X, nullptr); // nullptr�� �ʱ�ȭ
//
//		for (int x = 0; x < InvenSize.X; ++x)
//		{
//			// HUD�� ���� ���ο� ���� ����
//			ASlot* SlotWidget = HUD->CreateWidget<ASlot>(0, "SlotWidget").get();
//
//			if (SlotWidget == nullptr)
//			{
//				MSGASSERT("���� ���� ���� ����!");
//				continue;
//			}
//
//			// ���Ϳ� ������ ����
//			AllSlots[y][x] = SlotWidget;
//
//			// ��� ���� ����
//			if (UnlockedCount < OpenSlot)
//			{
//				SlotWidget->IsLocked = false; // Unlock
//			}
//			else
//			{
//				SlotWidget->IsLocked = true; // Lock
//			}
//
//			// `IsLocked` ���¿� ���� �ؽ�ó ����
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
    // 2D ���� ũ�� ����
    AllSlots.resize(InvenSize.Y); // Y(��) ũ�� ����

    int UnlockedCount = 0; // Unlock�� ���� ������ ���� ���� ����
    AHUD* HUD = GetWorld()->GetHUD<AHUD>(); // ���� HUD ��������

    if (HUD == nullptr)
    {
        MSGASSERT("HUD�� ã�� �� �����ϴ�.");
        return;
    }

    // �κ��丮�� ��ġ�� ũ�� �ݿ�
    FVector InventorySize = INVENTORY_Base * 0.94f; // �κ��丮 ũ�� ����
    FVector StartPosition = { INVENTORY_Pos.X - (InventorySize.X * ScaleRatio * 0.5f) + (InventorySize.X * ScaleRatio / (InvenSize.X * 2)), (InventorySize.Y * ScaleRatio) * 0.5f - (InventorySize.Y * ScaleRatio / (InvenSize.Y * 2)) };  // �⺻ �κ��丮 ��ġ

    // ���� �� ������ �κ��丮 ũ�⿡ �°� �ڵ� ����
    float SlotSpacingX = InventorySize.X / static_cast<float>(InvenSize.X) * ScaleRatio /** 0.8f*/ ;
    float SlotSpacingY = -InventorySize.Y / static_cast<float>(InvenSize.Y) * ScaleRatio /** 0.9f*/ ;

    for (int y = 0; y < InvenSize.Y; ++y)
    {
        AllSlots[y].resize(InvenSize.X, nullptr); // nullptr�� �ʱ�ȭ

        for (int x = 0; x < InvenSize.X; ++x)
        {
            // HUD�� ���� ���ο� ���� ����
            ASlot* SlotWidget = HUD->CreateWidget<ASlot>(0, "SlotWidget").get();

            if (SlotWidget == nullptr)
            {
                MSGASSERT("���� ���� ���� ����!");
                continue;
            }

            // ���Ϳ� ������ ����
            AllSlots[y][x] = SlotWidget;

            // ��� ���� ����
            if (UnlockedCount < OpenSlot)
            {
                SlotWidget->IsLocked = false; // Unlock
            }
            else
            {
                SlotWidget->IsLocked = true; // Lock
            }

            // `IsLocked` ���¿� ���� �ؽ�ó ����
            if (SlotWidget->IsLocked)
            {
                SlotWidget->SetTexture("Inventory_SlotLock.png", true, ScaleRatio);
            }
            else
            {
                SlotWidget->SetTexture("Inventory_Slot #1184.png", true, ScaleRatio);
            }

            // ���� ��ġ ��� �� ����
            FVector SlotPosition = StartPosition + FVector(x * SlotSpacingX, y * SlotSpacingY, 0.0f);
            SlotWidget->SetWorldLocation(SlotPosition);

            ++UnlockedCount;
        }
    }
}
