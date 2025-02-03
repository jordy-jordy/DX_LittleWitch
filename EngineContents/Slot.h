#pragma once
#include <EngineCore/Actor.h>
#include "Item.h"


// ���� :
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

	// ũ�� ���� �� ��������
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
	bool bLocked = false;           // ���� ��� ����
	AItem* Item = nullptr;          // ���Կ� ��� ������
	FVector SlotSize = { 50, 50 };   // ������ �⺻ ũ��

	class USpriteRenderer* Slot_Unlock;
	class USpriteRenderer* Slot_Lock;
};