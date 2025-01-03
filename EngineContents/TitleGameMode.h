#pragma once
#include <EngineCore/Actor.h>

// ���� :
class ATitleGameMode : public AActor
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
	std::shared_ptr<class ATitleScene> Title;
};

