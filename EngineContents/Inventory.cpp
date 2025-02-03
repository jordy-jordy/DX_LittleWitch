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
	// 2D 벡터 크기 조정
	AllSlots.resize(InvenSize.Y); // Y(행) 크기 설정

	for (int y = 0; y < InvenSize.Y; y++)
	{
		AllSlots[y].resize(InvenSize.X); // X(열) 크기 설정
	}
}
