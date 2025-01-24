#pragma once
#include <EngineCore/Actor.h>
#include "Item.h"


// 설명 :
class ASlot : public AActor
{
public:
	// constrcuter destructer
	ASlot();
	~ASlot();

	// delete Function
	ASlot(const ASlot& _Other) = delete;
	ASlot(ASlot&& _Other) noexcept = delete;
	ASlot& operator=(const ASlot& _Other) = delete;
	ASlot& operator=(ASlot&& _Other) noexcept = delete;

	void SetLocked(bool Locked)
	{
		bLocked = Locked;
	}

	bool IsLocked() const
	{
		return bLocked;
	}

	void SetItem(AItem* _Item)
	{
		Item = _Item;
	}

	AItem* GetItem() const
	{
		return Item;
	}

	// 크기 설정 및 가져오기
	void SetSize(const FVector& Size)
	{
		SlotSize = Size;
	}

	FVector GetSize() const
	{
		return SlotSize;
	}

	// 위치 설정 및 가져오기
	void SetPosition(const FVector& Position)
	{
		SlotPosition = Position;
	}
	FVector GetPosition() const
	{
		return SlotPosition;
	}


protected:


private:
	bool bLocked = false;           // 슬롯 잠금 여부
	AItem* Item = nullptr;          // 슬롯에 담긴 아이템
	FVector SlotSize = { 50, 50 };   // 슬롯의 기본 크기
	FVector SlotPosition = { 0, 0 }; // 슬롯의 위치

	std::shared_ptr<class USpriteRenderer> Slot_Unlock;
	std::shared_ptr<class USpriteRenderer> Slot_Lock;
};