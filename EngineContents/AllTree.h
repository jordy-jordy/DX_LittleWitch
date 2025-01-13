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
class AAllTree : public AActor
{
public:
	// constrcuter destructer
	AAllTree();
	~AAllTree();

	// delete Function
	AAllTree(const AAllTree& _Other) = delete;
	AAllTree(AAllTree&& _Other) noexcept = delete;
	AAllTree& operator=(const AAllTree& _Other) = delete;
	AAllTree& operator=(AAllTree&& _Other) noexcept = delete;

	ETreeType TreeTypeValue;

protected:

private:

};
