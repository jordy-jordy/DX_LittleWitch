#pragma once
#include <EngineCore/ImageWidget.h>

#include "GlobalVar.h"


class UItemInfo
{
public:
	bool IsStackable = true;	// true�� ��� �������� ���� �� ����
	int Cost = 1000;
	int ItemCount = 0;	// ������
	int SpriteIndex = 0;
	std::string_view Name;

};

class UItem : public UImageWidget
{
public:
	UItem();
	~UItem();

	UItemInfo GetItemInfo() const
	{
		return ItemInfo;
	}

	void SetItemInfo(bool _IsStackable, int _Cost, int _ItemCount, int _SpriteIndex, std::string_view _Name)
	{
		ItemInfo.IsStackable = _IsStackable;
		ItemInfo.Cost = _Cost;
		ItemInfo.ItemCount = _ItemCount;
		ItemInfo.SpriteIndex = _SpriteIndex;
		ItemInfo.Name = _Name;
	}


protected:

private:
	UItemInfo ItemInfo;


};
