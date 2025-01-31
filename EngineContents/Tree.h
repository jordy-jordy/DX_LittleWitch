#pragma once
#include "FieldObjects.h"


// Ό³Έν :
class ATree : public AFieldObjects
{
public:
	// constrcuter destructer
	ATree();
	~ATree();

	// delete Function
	ATree(const ATree& _Other) = delete;
	ATree(ATree&& _Other) noexcept = delete;
	ATree& operator=(const ATree& _Other) = delete;
	ATree& operator=(ATree&& _Other) noexcept = delete;

	USpriteRenderer* GetRenderer() override
	{
		return Renderer;
	}

	UCollision* GetCollision() override
	{
		return Collision;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;


private:
	USpriteRenderer* Renderer;
	USpriteRenderer* Renderer_Tree_000;
	USpriteRenderer* Renderer_Tree_001;
	USpriteRenderer* Renderer_Tree_002;
	USpriteRenderer* Renderer_Tree_003;
	USpriteRenderer* Renderer_Tree_004;
	USpriteRenderer* Renderer_Tree_005;
	USpriteRenderer* Renderer_Tree_006;
	UCollision* Collision;

};
