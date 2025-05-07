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

void UInventory::SlotInit(std::string_view _Left, std::string_view _Right)
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
	float SlotSpacingX = InventorySize.X / static_cast<float>(InvenSize.X) * ScaleRatio /** 0.8f*/;
	float SlotSpacingY = -InventorySize.Y / static_cast<float>(InvenSize.Y) * ScaleRatio /** 0.9f*/;

	for (int y = 0; y < InvenSize.Y; ++y)
	{
		AllSlots[y].resize(InvenSize.X, nullptr); // nullptr로 초기화

		for (int x = 0; x < InvenSize.X; ++x)
		{
			// HUD를 통해 새로운 슬롯 생성
			SlotWidget = HUD->CreateWidget<USlot>(0, "SlotWidget").get();

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
				SlotWidget->SetTexture(_Left, true, ScaleRatio);
				SlotWidget->SetActive(false);
			}
			else
			{
				SlotWidget->SetTexture(_Right, true, ScaleRatio);
				SlotWidget->SetActive(false);
			}

			// 슬롯 위치 계산 후 설정
			FVector SlotPosition = StartPosition + FVector(x * SlotSpacingX, y * SlotSpacingY, 0.0f);
			SlotWidget->SetWorldLocation(SlotPosition);

			++UnlockedCount;
		}
	}
}

void UInventory::SetAllSlotsActiveSwitch()
{
	for (int y = 0; y < InvenSize.Y; ++y)
	{
		for (int x = 0; x < InvenSize.X; ++x)
		{
			if (AllSlots[y][x] != nullptr)
			{
				AllSlots[y][x]->SetActiveSwitch();
			}
		}
	}
}

bool UInventory::AddItem(const UItem* _NewItem, int _ItemCount)
{
	if (_NewItem == nullptr)
	{
		return false;
	}

	// 1. 스택 가능한 아이템이면 기존 슬롯에 추가
	if (_NewItem->GetItemInfo().IsStackable)
	{
		for (int y = 0; y < InvenSize.Y; ++y)
		{
			for (int x = 0; x < InvenSize.X; ++x)
			{
				USlot* _Slot = AllSlots[y][x];
				if (_Slot == nullptr || _Slot->IsLocked)
				{
					continue;
				}

				if (_Slot->IsHaveItem && _Slot->Item.GetItemInfo().Name == _NewItem->GetItemInfo().Name)
				{
					// 기존 슬롯에 수량 추가
					_Slot->Item.SetItemInfo(
						_Slot->Item.GetItemInfo().IsStackable,
						_Slot->Item.GetItemInfo().Cost,
						_Slot->Item.GetItemInfo().ItemCount + _ItemCount, // 개수 추가
						_Slot->Item.GetItemInfo().SpriteIndex,
						_Slot->Item.GetItemInfo().Name
					);

					// 기존 슬롯의 텍스처 업데이트 (UI 반영)
					_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

					return true; // 기존 슬롯에 추가 완료
				}
			}
		}

		// 2. 기존 슬롯에 없으면 새 슬롯을 찾아 추가 (최초 습득)
		for (int y = 0; y < InvenSize.Y; ++y)
		{
			for (int x = 0; x < InvenSize.X; ++x)
			{
				USlot* _Slot = AllSlots[y][x];
				if (_Slot == nullptr || _Slot->IsLocked || _Slot->IsHaveItem)
				{
					continue;
				}

				// 새로운 아이템을 슬롯에 추가 (최초 습득)
				_Slot->Item.SetItemInfo(
					_NewItem->GetItemInfo().IsStackable,
					_NewItem->GetItemInfo().Cost,
					_ItemCount, // 최초 습득 시 전체 개수 추가
					_NewItem->GetItemInfo().SpriteIndex,
					_NewItem->GetItemInfo().Name
				);

				_Slot->IsHaveItem = true;

				// 아이템의 텍스처를 슬롯에 적용
				_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

				return true; // 아이템 추가 완료
			}
		}
	}

	// 3. 스택 불가능한 아이템이면 각 슬롯에 1개씩 배치
	int _AddedCount = 0;

	for (int y = 0; y < InvenSize.Y && _AddedCount < _ItemCount; ++y)
	{
		for (int x = 0; x < InvenSize.X && _AddedCount < _ItemCount; ++x)
		{
			USlot* _Slot = AllSlots[y][x];
			if (_Slot == nullptr || _Slot->IsLocked || _Slot->IsHaveItem)
			{
				continue;
			}

			// 새로운 아이템을 슬롯에 추가 (스택 불가능 → 한 슬롯에 1개씩)
			_Slot->Item.SetItemInfo(
				_NewItem->GetItemInfo().IsStackable,
				_NewItem->GetItemInfo().Cost,
				1, // 스택 불가능 => 한 슬롯에 1개만
				_NewItem->GetItemInfo().SpriteIndex,
				_NewItem->GetItemInfo().Name
			);

			_Slot->IsHaveItem = true;

			// 아이템의 텍스처를 슬롯에 적용
			_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

			_AddedCount++;
		}
	}

	return _AddedCount == _ItemCount; // 모든 아이템이 성공적으로 추가되었는지 확인
}
