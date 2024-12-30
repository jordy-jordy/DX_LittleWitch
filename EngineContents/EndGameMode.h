#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class AEndGameMode : public AActor
{
public:
	// constrcuter destructer
	AEndGameMode();
	~AEndGameMode();

	// delete Function
	AEndGameMode(const AEndGameMode& _Other) = delete;
	AEndGameMode(AEndGameMode&& _Other) noexcept = delete;
	AEndGameMode& operator=(const AEndGameMode& _Other) = delete;
	AEndGameMode& operator=(AEndGameMode&& _Other) noexcept = delete;

protected:

private:

};
