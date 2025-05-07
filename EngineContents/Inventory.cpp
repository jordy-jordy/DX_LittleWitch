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
	float SlotSpacingX = InventorySize.X / static_cast<float>(InvenSize.X) * ScaleRatio /** 0.8f*/;
	float SlotSpacingY = -InventorySize.Y / static_cast<float>(InvenSize.Y) * ScaleRatio /** 0.9f*/;

	for (int y = 0; y < InvenSize.Y; ++y)
	{
		AllSlots[y].resize(InvenSize.X, nullptr); // nullptr�� �ʱ�ȭ

		for (int x = 0; x < InvenSize.X; ++x)
		{
			// HUD�� ���� ���ο� ���� ����
			SlotWidget = HUD->CreateWidget<USlot>(0, "SlotWidget").get();

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
				SlotWidget->SetTexture(_Left, true, ScaleRatio);
				SlotWidget->SetActive(false);
			}
			else
			{
				SlotWidget->SetTexture(_Right, true, ScaleRatio);
				SlotWidget->SetActive(false);
			}

			// ���� ��ġ ��� �� ����
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

	// 1. ���� ������ �������̸� ���� ���Կ� �߰�
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
					// ���� ���Կ� ���� �߰�
					_Slot->Item.SetItemInfo(
						_Slot->Item.GetItemInfo().IsStackable,
						_Slot->Item.GetItemInfo().Cost,
						_Slot->Item.GetItemInfo().ItemCount + _ItemCount, // ���� �߰�
						_Slot->Item.GetItemInfo().SpriteIndex,
						_Slot->Item.GetItemInfo().Name
					);

					// ���� ������ �ؽ�ó ������Ʈ (UI �ݿ�)
					_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

					return true; // ���� ���Կ� �߰� �Ϸ�
				}
			}
		}

		// 2. ���� ���Կ� ������ �� ������ ã�� �߰� (���� ����)
		for (int y = 0; y < InvenSize.Y; ++y)
		{
			for (int x = 0; x < InvenSize.X; ++x)
			{
				USlot* _Slot = AllSlots[y][x];
				if (_Slot == nullptr || _Slot->IsLocked || _Slot->IsHaveItem)
				{
					continue;
				}

				// ���ο� �������� ���Կ� �߰� (���� ����)
				_Slot->Item.SetItemInfo(
					_NewItem->GetItemInfo().IsStackable,
					_NewItem->GetItemInfo().Cost,
					_ItemCount, // ���� ���� �� ��ü ���� �߰�
					_NewItem->GetItemInfo().SpriteIndex,
					_NewItem->GetItemInfo().Name
				);

				_Slot->IsHaveItem = true;

				// �������� �ؽ�ó�� ���Կ� ����
				_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

				return true; // ������ �߰� �Ϸ�
			}
		}
	}

	// 3. ���� �Ұ����� �������̸� �� ���Կ� 1���� ��ġ
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

			// ���ο� �������� ���Կ� �߰� (���� �Ұ��� �� �� ���Կ� 1����)
			_Slot->Item.SetItemInfo(
				_NewItem->GetItemInfo().IsStackable,
				_NewItem->GetItemInfo().Cost,
				1, // ���� �Ұ��� => �� ���Կ� 1����
				_NewItem->GetItemInfo().SpriteIndex,
				_NewItem->GetItemInfo().Name
			);

			_Slot->IsHaveItem = true;

			// �������� �ؽ�ó�� ���Կ� ����
			_Slot->SetTexture(_NewItem->GetItemInfo().Name, true, ScaleRatio);

			_AddedCount++;
		}
	}

	return _AddedCount == _ItemCount; // ��� �������� ���������� �߰��Ǿ����� Ȯ��
}
