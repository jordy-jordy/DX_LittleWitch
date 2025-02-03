#pragma once
#include <EngineCore/HUD.h>

// Ό³Έν :
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

	void BeginPlay();
	void Tick(float _DeltaTime);


protected:


private:

};
