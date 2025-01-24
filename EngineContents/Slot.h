#pragma once
#include <EngineCore/Actor.h>
#include "Item.h"


// ���� :
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

	// ũ�� ���� �� ��������
	void SetSize(const FVector& Size)
	{
		SlotSize = Size;
	}

	FVector GetSize() const
	{
		return SlotSize;
	}

	// ��ġ ���� �� ��������
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
	bool bLocked = false;           // ���� ��� ����
	AItem* Item = nullptr;          // ���Կ� ��� ������
	FVector SlotSize = { 50, 50 };   // ������ �⺻ ũ��
	FVector SlotPosition = { 0, 0 }; // ������ ��ġ

	std::shared_ptr<class USpriteRenderer> Slot_Unlock;
	std::shared_ptr<class USpriteRenderer> Slot_Lock;
};