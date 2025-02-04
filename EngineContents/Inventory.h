#pragma once
#include <EngineCore/ImageWidget.h>
#include "Item.h"


class USlot : public UImageWidget
{
public:
	bool IsLocked = false;
	bool IsHaveItem = false;
	FVector SlotScale = { 20, 20 };

	UItem Item;
};

class UInventory : public UImageWidget
{
public:
	// constrcuter destructer
	UInventory();
	~UInventory();

	// delete Function
	UInventory(const UInventory& _Other) = delete;
	UInventory(UInventory&& _Other) noexcept = delete;
	UInventory& operator=(const UInventory& _Other) = delete;
	UInventory& operator=(UInventory&& _Other) noexcept = delete;

	void SlotInit(std::string_view _Left = "EmptySlot.png", std::string_view _Right = "EmptySlot.png");
	void SetAllSlotsActiveSwitch();
	bool AddItem(const UItem* _NewItem, int _ItemCount);


protected:
	void Tick(float _DeltaTime);

private:
private:
	std::vector<std::vector<USlot*>> AllSlots; 
	USlot* SlotWidget;

};