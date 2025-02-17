#pragma once
#include <EngineCore/HUD.h>

// ���� :
class AWitchHUD : public AHUD
{
public:
	// constrcuter destructer
	AWitchHUD();
	~AWitchHUD();

	// delete Function
	AWitchHUD(const AWitchHUD& _Other) = delete;
	AWitchHUD(AWitchHUD&& _Other) noexcept = delete;
	AWitchHUD& operator=(const AWitchHUD& _Other) = delete;
	AWitchHUD& operator=(AWitchHUD&& _Other) noexcept = delete;


protected:
	void BeginPlay();
	void Tick(float _DeltaTime);


private:
	class UInventory* BackInventory = nullptr;
	class UInventory* FrontInventory = nullptr;

	class UItem* MongsiriWater;
	class UItem* WitchFlower;
};
