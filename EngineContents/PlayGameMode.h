#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class APlayGameMode : public AGameMode
{
public:
	// constrcuter destructer
	APlayGameMode();
	~APlayGameMode();

	// delete Function
	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

	void PlayDirLoad();
	void PlaySpritesInit();


protected:
	void Tick(float _DeltaTime);
	void BeginPlay();

private:
	class APlayer* Player;
	std::shared_ptr<class AAllField> Field_HOME;

};
