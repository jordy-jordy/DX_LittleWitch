#pragma once
#include <EngineCore/Actor.h>


enum class ETreeType
{
	NONE = 0,
	Tree0 = 1,
	Tree1 = 2,
	Tree2 = 3,
	Tree3 = 4,
	Tree4 = 5,
	Tree5 = 6,
	Tree6 = 7,
	Max
};

// Ό³Έν :
class AFieldObjects : public AActor
{
public:
	// constrcuter destructer
	AFieldObjects();
	~AFieldObjects();

	// delete Function
	AFieldObjects(const AFieldObjects& _Other) = delete;
	AFieldObjects(AFieldObjects&& _Other) noexcept = delete;
	AFieldObjects& operator=(const AFieldObjects& _Other) = delete;
	AFieldObjects& operator=(AFieldObjects&& _Other) noexcept = delete;

	ETreeType TreeTypeValue = ETreeType::NONE;

	virtual std::shared_ptr<class USpriteRenderer> GetRenderer() = 0;
	virtual std::shared_ptr<class UCollision> GetCollision() = 0;


protected:

private:

};
