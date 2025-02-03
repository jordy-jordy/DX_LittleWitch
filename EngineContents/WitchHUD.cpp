#include "PreCompile.h"
#include "WitchHUD.h"

#include <EngineCore/ImageWidget.h>

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
		std::shared_ptr<UImageWidget> BaseInventory = CreateWidget<UImageWidget>(-1);
		BaseInventory->SetScale3D({ INVENTORY_Base * ScaleRatio });
		BaseInventory->SetTexture("Inventory_Base_mod.png");
	}
	

}

void AWitchHUD::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}
