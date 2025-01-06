#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class APlayGameMode : public AActor
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
	std::shared_ptr<class APawn> Player;
	std::shared_ptr<class AActor> MainField;

};
