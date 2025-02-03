#pragma once
#include <EngineCore/Actor.h>
#include "Item.h"


// 설명 :
class ASlot0 : public AActor
{
public:
	// constrcuter destructer
	ASlot0();
	~ASlot0();

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



protected:


private:
	bool bLocked = false;           // 슬롯 잠금 여부
	AItem* Item = nullptr;          // 슬롯에 담긴 아이템
	FVector SlotSize = { 50, 50 };   // 슬롯의 기본 크기

	class USpriteRenderer* Slot_Unlock;
	class USpriteRenderer* Slot_Lock;
};