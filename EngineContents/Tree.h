#pragma once
#include "FieldObjects.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>


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

	std::shared_ptr<class USpriteRenderer> GetRenderer() override
	{
		return Renderer;
	}

	std::shared_ptr<class UCollision> GetCollision() override
	{
		return Collision;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;


private:
	std::shared_ptr<class USpriteRenderer> Renderer;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_000;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_001;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_002;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_003;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_004;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_005;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_006;
	std::shared_ptr<class UCollision> Collision;

};
