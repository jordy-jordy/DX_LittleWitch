#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class ATitleScene : public AActor
{
public:
	// constrcuter destructer
	ATitleScene();
	~ATitleScene();

	// delete Function
	ATitleScene(const ATitleScene& _Other) = delete;
	ATitleScene(ATitleScene&& _Other) noexcept = delete;
	ATitleScene& operator=(const ATitleScene& _Other) = delete;
	ATitleScene& operator=(ATitleScene&& _Other) noexcept = delete;

	void SetLocation_Window(class USpriteRenderer* _Renderer, FVector _Value);

	//std::shared_ptr<class USpriteRenderer> GetRenderer()
	//{
	//	return LogoRenderer;
	//}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	class USpriteRenderer* LOGO;
	class USpriteRenderer* BG_SKY;
	class USpriteRenderer* BG_WATER;
	class USpriteRenderer* MOUNTAIN;
	class USpriteRenderer* MOUNTAIN_SHADOW;
	class USpriteRenderer* WATER_GLARE;
	class USpriteRenderer* WATER_SHINE;
	class USpriteRenderer* SKY_MOON;
	class USpriteRenderer* SKY_STAR;
	class USpriteRenderer* TRAIN0;
	class USpriteRenderer* TRAIN0_LIGHT;
	class USpriteRenderer* TRAIN1;
	class USpriteRenderer* TRAIN1_LIGHT;
	class USpriteRenderer* TRAIN2;
	class USpriteRenderer* TRAIN2_LIGHT;
	class USpriteRenderer* TRAIN3;
	class USpriteRenderer* TRAIN3_LIGHT;
	class USpriteRenderer* TRAIN4;
	class USpriteRenderer* TRAIN_BRIDGE;
	class USpriteRenderer* TRAIN_LIGHT_BLUR0;
	class USpriteRenderer* TRAIN_LIGHT_BLUR1;
	class USpriteRenderer* BRIDGE_SHADOW0;
	class USpriteRenderer* BRIDGE_SHADOW1;
	class USpriteRenderer* TRAIN_SHADOW;
	class USpriteRenderer* CLOUD_FAR;
	class USpriteRenderer* CLOUD_MID;
	class USpriteRenderer* CLOUD_NEAR;
	class USpriteRenderer* TREE_0;
	class USpriteRenderer* TREE_1;
};
