#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class AField_Home : public AActor
{
public:
	// constrcuter destructer
	AField_Home();
	~AField_Home();

	// delete Function
	AField_Home(const AField_Home& _Other) = delete;
	AField_Home(AField_Home&& _Other) noexcept = delete;
	AField_Home& operator=(const AField_Home& _Other) = delete;
	AField_Home& operator=(AField_Home&& _Other) noexcept = delete;

	FVector GetHomeFieldSize()
	{
		return HomeFieldSize;
	}

	std::shared_ptr<class UCollision> GetMainField_Coll()
	{
		return HomeField_Coll;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector HomeFieldSize = { 1280.0f * 0.8f, 720.0f * 0.8f, 0.0f };

	std::shared_ptr<class USpriteRenderer> HomeField;
	std::shared_ptr<class UCollision> HomeField_Coll;
};
