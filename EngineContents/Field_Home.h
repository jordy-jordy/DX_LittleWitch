#pragma once
#include <EngineCore/Actor.h>

#include "GlobalVar.h"


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


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> HomeField;
	std::shared_ptr<class UCollision> HomeField_Coll;
	
	std::shared_ptr<class USpriteRenderer> HomeField_ColImage;
};
