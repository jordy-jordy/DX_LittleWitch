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

	static FVector GetMainFieldSize()
	{
		return MainFieldSize;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	static inline FVector MainFieldSize = { 300.0f, 300.0f, 0.0f };
	std::shared_ptr<class USpriteRenderer> MainField;

	std::shared_ptr<class UCollision> MainField_Coll;
};
