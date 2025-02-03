#pragma once
#include <EngineCore/ImageWidget.h>
#include <EngineCore/SpriteRenderer.h>

class ASlot 
{
public:
	class USpriteRenderer* Slot_Unlock;
	class USpriteRenderer* Slot_Lock;

	bool IsLocked = false;
	bool IsHaveItem = false;
	FVector SlotScale = { 50, 50 };

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

protected:
	void Tick(float _DeltaTime);

private:
	std::vector<std::vector<ASlot>> AllSlots;
	FIntPoint InvenSize = {4, 3};

};