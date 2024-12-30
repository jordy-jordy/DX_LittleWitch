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

	void SetLocation_Window(const std::shared_ptr<class USpriteRenderer> _Renderer, const FVector _value);

	//std::shared_ptr<class USpriteRenderer> GetRenderer()
	//{
	//	return LogoRenderer;
	//}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> LOGO;
	std::shared_ptr<class USpriteRenderer> BG_SKY;
	std::shared_ptr<class USpriteRenderer> BG_WATER;
	std::shared_ptr<class USpriteRenderer> WATER_GLARE;
	std::shared_ptr<class USpriteRenderer> SKY_MOON;
	std::shared_ptr<class USpriteRenderer> SKY_STAR;
	std::shared_ptr<class USpriteRenderer> TRAIN0;
	std::shared_ptr<class USpriteRenderer> TRAIN0_LIGHT;
	std::shared_ptr<class USpriteRenderer> TRAIN1;
	std::shared_ptr<class USpriteRenderer> TRAIN1_LIGHT;
	std::shared_ptr<class USpriteRenderer> TRAIN2;
	std::shared_ptr<class USpriteRenderer> TRAIN2_LIGHT;
	std::shared_ptr<class USpriteRenderer> TRAIN3;
	std::shared_ptr<class USpriteRenderer> TRAIN_BRIDGE;
};
