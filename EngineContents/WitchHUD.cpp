#include "PreCompile.h"
#include "WitchHUD.h"

#include <EngineCore/ImageWidget.h>

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
		std::shared_ptr<UInventory> BaseInventory = CreateWidget<UInventory>(-500);
		BaseInventory->SetScale3D({ INVENTORY_Base * ScaleRatio });
		BaseInventory->SetWorldLocation({ -400, 0 });
		BaseInventory->SetTexture("Inventory_Base_mod.png");

		BaseInventory->SlotInit();
	}
	

}

void AWitchHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}
