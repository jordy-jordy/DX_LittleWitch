#pragma once
#include <EngineCore/ImageWidget.h>
#include <EngineCore/SpriteRenderer.h>

class ASlot : public UImageWidget
{
public:
	bool IsLocked = false;
	bool IsHaveItem = false;
	FVector SlotScale = { 20, 20 };

	class AItem* Item = nullptr;
};

// Ό³Έν :
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

	void SlotInit();

	ASlot* GetSlotWidget()
	{
		return SlotWidget;
	}

	void SetAllSlotsActiveSwitch();


protected:
	void Tick(float _DeltaTime);

private:
private:
	std::vector<std::vector<ASlot*>> AllSlots; 
	ASlot* SlotWidget;

};