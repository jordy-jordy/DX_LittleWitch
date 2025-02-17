#pragma once
#include <EngineCore/GameMode.h>


// ���� :
class ATitleGameMode : public AGameMode
{
public:
	// constrcuter destructer
	ATitleGameMode();
	~ATitleGameMode();

	// delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

	void TitleDirLoad();
	void TitleSpritesInit();


protected:
	void Tick(float _DeltaTime);
	void BeginPlay();


private:
	class AActor* Title;
};

