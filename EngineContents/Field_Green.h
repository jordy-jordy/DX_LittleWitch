#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class AField_Green : public AActor
{
public:
	// constrcuter destructer
	AField_Green();
	~AField_Green();

	// delete Function
	AField_Green(const AField_Green& _Other) = delete;
	AField_Green(AField_Green&& _Other) noexcept = delete;
	AField_Green& operator=(const AField_Green& _Other) = delete;
	AField_Green& operator=(AField_Green&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};
