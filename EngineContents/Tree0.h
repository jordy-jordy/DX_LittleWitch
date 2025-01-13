#pragma once
#include "AllTree.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>


// Ό³Έν :
class ATree0 : public AAllTree
{
public:
	// constrcuter destructer
	ATree0();
	~ATree0();

	// delete Function
	ATree0(const ATree0& _Other) = delete;
	ATree0(ATree0&& _Other) noexcept = delete;
	ATree0& operator=(const ATree0& _Other) = delete;
	ATree0& operator=(ATree0&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return Renderer_Tree_000;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;


private:
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_000;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_001;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_002;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_003;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_004;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_005;
	std::shared_ptr<class USpriteRenderer> Renderer_Tree_006;
	std::shared_ptr<class UCollision> Collision;

};
