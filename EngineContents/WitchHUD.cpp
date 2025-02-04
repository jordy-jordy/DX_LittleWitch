#include "PreCompile.h"
#include "WitchHUD.h"

#include <EngineCore/ImageWidget.h>
#include <EnginePlatform/EngineInput.h>

#include "Inventory.h"
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

	{
		BaseInventory = CreateWidget<UInventory>(-500).get();
		BaseInventory->SetScale3D({ INVENTORY_Base * ScaleRatio });
		BaseInventory->SetWorldLocation(INVENTORY_Pos);
		BaseInventory->SetTexture("Inventory_Base.png");
		BaseInventory->SlotInit();
		BaseInventory->SetActive(false);
	}
	

}

void AWitchHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);

	if (UEngineInput::IsDown('I'))
	{
		BaseInventory->SetActiveSwitch();
		BaseInventory->SetAllSlotsActiveSwitch();

	}
}
