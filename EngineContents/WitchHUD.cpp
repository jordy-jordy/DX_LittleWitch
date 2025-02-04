#include "PreCompile.h"
#include "WitchHUD.h"

#include <EngineCore/ImageWidget.h>
#include <EnginePlatform/EngineInput.h>

#include "Inventory.h"
#include "Item.h"
#include "GlobalVar.h"


AWitchHUD::AWitchHUD()
{
}

AWitchHUD::~AWitchHUD()
{
}

void AWitchHUD::BeginPlay()
{
	AHUD::BeginPlay();

	BackInventory = CreateWidget<UInventory>(-10).get();
	BackInventory->SetScale3D({ INVENTORY_Base * ScaleRatio });
	BackInventory->SetWorldLocation(INVENTORY_Pos);
	BackInventory->SetTexture("Inventory_Base.png");
	BackInventory->SlotInit("Inventory_SlotLock.png", "Inventory_Slot #1184.png");
	BackInventory->SetActive(false);

	FrontInventory = CreateWidget<UInventory>(-20).get();
	FrontInventory->SetScale3D({ INVENTORY_Base * ScaleRatio });
	FrontInventory->SetWorldLocation(INVENTORY_Pos);
	FrontInventory->SlotInit();
	FrontInventory->SetActive(false);

	UItem* MongsiriWater = CreateWidget<UItem>(-25).get();
	MongsiriWater->SetItemInfo(true, 100, 0, 0, "Mongsiri_Water.png");
	MongsiriWater->SetTexture("Mongsiri_Water.png", true, ScaleRatio);

	UItem* WitchFlower = CreateWidget<UItem>(-25).get();
	WitchFlower->SetItemInfo(true, 100, 0, 0, "WitchFlower_Collect.png");
	WitchFlower->SetTexture("WitchFlower_Collect.png", true, ScaleRatio);

	FrontInventory->AddItem(MongsiriWater, 3);
	FrontInventory->AddItem(WitchFlower, 6);

}

void AWitchHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);

	if (UEngineInput::IsDown('I'))
	{
		BackInventory->SetActiveSwitch();
		BackInventory->SetAllSlotsActiveSwitch();
		FrontInventory->SetActiveSwitch();
		FrontInventory->SetAllSlotsActiveSwitch();

	}
}
