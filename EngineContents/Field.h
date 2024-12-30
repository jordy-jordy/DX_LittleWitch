#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class AField : public AActor
{
public:
	// constrcuter destructer
	AField();
	~AField();

	// delete Function
	AField(const AField& _Other) = delete;
	AField(AField&& _Other) noexcept = delete;
	AField& operator=(const AField& _Other) = delete;
	AField& operator=(AField&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

};
