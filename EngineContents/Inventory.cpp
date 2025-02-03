#include "PreCompile.h"
#include "Inventory.h"

#include <EngineCore/ImageWidget.h>

#include "Slot.h"


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

void UInventory::SlotInit()
{
	// 2D ���� ũ�� ����
	AllSlots.resize(InvenSize.Y); // Y(��) ũ�� ����

	for (int y = 0; y < InvenSize.Y; y++)
	{
		AllSlots[y].resize(InvenSize.X); // X(��) ũ�� ����
	}
}
