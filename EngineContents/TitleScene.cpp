#include "PreCompile.h"
#include "TitleScene.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>

#include "GlobalVar.h"

ATitleScene::ATitleScene()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	BG_SKY = CreateDefaultSubObject<USpriteRenderer>();
	BG_SKY->SetSprite("Title_Train_Sky.png", 0);
	BG_SKY->SetRelativeScale3D({ 1280.0f, 720.0f, 1.0f });
	SetLocation_Window(BG_SKY, { 0,0,0 });

	BG_WATER = CreateDefaultSubObject<USpriteRenderer>();
	BG_WATER->SetSprite("Title_Train_Water.png", 0);
	BG_WATER->SetRelativeScale3D({ 1280.0f, 195.0f, 1.0f });
	SetLocation_Window(BG_WATER, { 0, 525.0f, 0 });

	SKY_STAR = CreateDefaultSubObject<USpriteRenderer>();
	SKY_STAR->SetSprite("Title_train_star.png", 0);
	SKY_STAR->CreateAnimation("STARS", "Title_train_star.png", 0, 4, 0.15f);
	SKY_STAR->SetRelativeScale3D({ 1275.0f, 352.0f, 1.0f });
	SetLocation_Window(SKY_STAR, { 0.0f, 0.0f, 0 });
	SKY_STAR->ChangeAnimation("STARS");

	MOUNTAIN = CreateDefaultSubObject<USpriteRenderer>();
	MOUNTAIN->SetSprite("Title_Train_Mountain.png", 0);
	MOUNTAIN->SetRelativeScale3D({ 1315.0f, 304.0f, 1.0f });
	SetLocation_Window(MOUNTAIN, { -389.0f, 216.0f, 0 });

	SKY_MOON = CreateDefaultSubObject<USpriteRenderer>();
	SKY_MOON->SetSprite("Title_Train_Moon.png", 0);
	SKY_MOON->SetRelativeScale3D({ 171.0f, 171.0f, 1.0f });
	SetLocation_Window(SKY_MOON, { 229.0f, 66.0f, 0 });

	TRAIN0 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN0->SetSprite("Title_Train_Train_0.png", 0);
	TRAIN0->SetRelativeScale3D({ 259.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN0, { 615.0f, 431.0f, 0 });

	TRAIN0_LIGHT = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN0_LIGHT->SetSprite("Title_Train_Window_0.png", 0);
	TRAIN0_LIGHT->SetRelativeScale3D({ 172.0f, 28.0f, 1.0f });
	SetLocation_Window(TRAIN0_LIGHT, { 631.0f, 455.0f, 0 });

	TRAIN1 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN1->SetSprite("Title_Train_Train_1.png", 0);
	TRAIN1->SetRelativeScale3D({ 152.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN1, { 466.0f, 431.0f, 0 });

	TRAIN1_LIGHT = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN1_LIGHT->SetSprite("Title_Train_Window_1.png", 0);
	TRAIN1_LIGHT->SetRelativeScale3D({ 142.0f, 36.0f, 1.0f });
	SetLocation_Window(TRAIN1_LIGHT, { 473.0f, 449.0f, 0 });

	TRAIN2 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN2->SetSprite("Title_Train_Train_1.png", 0);
	TRAIN2->SetRelativeScale3D({ 152.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN2, { 317.0f, 431.0f, 0 });

	TRAIN2_LIGHT = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN2_LIGHT->SetSprite("Title_Train_Window_1.png", 0);
	TRAIN2_LIGHT->SetRelativeScale3D({ 142.0f, 36.0f, 1.0f });
	SetLocation_Window(TRAIN2_LIGHT, { 325.0f, 449.0f, 0 });

	TRAIN3 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN3->SetSprite("Title_Train_Train_3.png", 0);
	TRAIN3->SetRelativeScale3D({ 299.0f, 70.0f, 1.0f });
	SetLocation_Window(TRAIN3, { 21.0f, 432.0f, 0 });

	TRAIN3_LIGHT = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN3_LIGHT->SetSprite("Title_Train_Light.png", 0);
	TRAIN3_LIGHT->SetRelativeScale3D({ 221.0f, 17.0f, 1.0f });
	SetLocation_Window(TRAIN3_LIGHT, { 67.0f, 467.0f, 0 });

	TRAIN4 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN4->SetSprite("Title_Train_Train_3.png", 0);
	TRAIN4->SetRelativeScale3D({ 299.0f, 70.0f, 1.0f });
	SetLocation_Window(TRAIN4, { -275.0f, 432.0f, 0 });

	TRAIN_SHADOW = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN_SHADOW->SetSprite("Title_Train_TrainWater_blur.png", 0);
	TRAIN_SHADOW->SetRelativeScale3D({ 870.0f, 53.0f, 1.0f });
	SetLocation_Window(TRAIN_SHADOW, { 0.0f, 658.0f, 0 });

	MOUNTAIN_SHADOW = CreateDefaultSubObject<USpriteRenderer>();
	MOUNTAIN_SHADOW->SetSprite("Title_Train_MountainWater_blur.png", 0);
	MOUNTAIN_SHADOW->SetRelativeScale3D({ 1297.0f, 222.0f, 1.0f });
	SetLocation_Window(MOUNTAIN_SHADOW, { -371.0f, 520.0f, 0 });

	BRIDGE_SHADOW1 = CreateDefaultSubObject<USpriteRenderer>();
	BRIDGE_SHADOW1->SetSprite("Title_Train_Bridge_Down.png", 0);
	BRIDGE_SHADOW1->SpriteData.CuttingPos.W = 0.3f;
	BRIDGE_SHADOW1->SetRelativeScale3D({ 1404.0f, 32.0f, 1.0f });
	SetLocation_Window(BRIDGE_SHADOW1, { -59.0f, 630.0f, 0 });

	WATER_GLARE = CreateDefaultSubObject<USpriteRenderer>();
	WATER_GLARE->SetSprite("Title_Train_WaterShine_blur.png", 0);
	WATER_GLARE->SetRelativeScale3D({ 1335.0f, 180.0f, 1.0f });
	SetLocation_Window(WATER_GLARE, { -29.0f, 563.0f, 0 });

	BRIDGE_SHADOW0 = CreateDefaultSubObject<USpriteRenderer>();
	BRIDGE_SHADOW0->SetSprite("Title_Train_Bridge_Shadow.png", 0);
	BRIDGE_SHADOW0->SetRelativeScale3D({ 1300.0f, 81.0f, 1.0f });
	SetLocation_Window(BRIDGE_SHADOW0, { -10.0f, 595.0f, 0 });

	TRAIN_LIGHT_BLUR0 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN_LIGHT_BLUR0->SetSprite("Title_Train_WindowWater_blur.png", 0);
	TRAIN_LIGHT_BLUR0->SetRelativeScale3D({ 540.0f, 69.0f, 1.0f });
	SetLocation_Window(TRAIN_LIGHT_BLUR0, { 292.0f, 645.0f, 0 });

	TRAIN_LIGHT_BLUR1 = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN_LIGHT_BLUR1->SetSprite("Title_Train_Light_Blur.png", 0);
	TRAIN_LIGHT_BLUR1->SetRelativeScale3D({ 287.0f, 39.0f, 1.0f });
	SetLocation_Window(TRAIN_LIGHT_BLUR1, { 21.0f, 656.0f, 0 });

	TRAIN_BRIDGE = CreateDefaultSubObject<USpriteRenderer>();
	TRAIN_BRIDGE->SetSprite("Title_Train_Bridge.png", 0);
	TRAIN_BRIDGE->SetRelativeScale3D({ 1404.0f, 133.0f, 1.0f });
	SetLocation_Window(TRAIN_BRIDGE, { -62.0f, 502.0f, 0 });

	WATER_SHINE = CreateDefaultSubObject<USpriteRenderer>();
	WATER_SHINE->SetSprite("Title_Train_WaterShine.png", 0);
	WATER_SHINE->SetRelativeScale3D({ 1257.0f, 3.0f, 1.0f });
	SetLocation_Window(WATER_SHINE, { -62.0f, 635.0f, 0 });

	LOGO = CreateDefaultSubObject<USpriteRenderer>();
	LOGO->SetSprite("Logo.png", 0);
	LOGO->SetRelativeScale3D({ 451.0f, 220.0f, 1.0f });
	SetLocation_Window(LOGO, {817.0f, 116.0f, 0});

	BG_SKY->SetupAttachment(RootComponent);
	BG_WATER->SetupAttachment(RootComponent);
	SKY_STAR->SetupAttachment(RootComponent);
	MOUNTAIN->SetupAttachment(RootComponent);
	SKY_MOON->SetupAttachment(RootComponent);
	TRAIN0->SetupAttachment(RootComponent);
	TRAIN0_LIGHT->SetupAttachment(RootComponent);
	TRAIN1->SetupAttachment(RootComponent);
	TRAIN1_LIGHT->SetupAttachment(RootComponent);
	TRAIN2->SetupAttachment(RootComponent);
	TRAIN2_LIGHT->SetupAttachment(RootComponent);
	TRAIN3->SetupAttachment(RootComponent);
	TRAIN3_LIGHT->SetupAttachment(RootComponent);
	TRAIN4->SetupAttachment(RootComponent);
	TRAIN_SHADOW->SetupAttachment(RootComponent);
	MOUNTAIN_SHADOW->SetupAttachment(RootComponent);
	BRIDGE_SHADOW1->SetupAttachment(RootComponent);
	WATER_GLARE->SetupAttachment(RootComponent);
	BRIDGE_SHADOW0->SetupAttachment(RootComponent);
	TRAIN_LIGHT_BLUR0->SetupAttachment(RootComponent);
	TRAIN_LIGHT_BLUR1->SetupAttachment(RootComponent);
	TRAIN_BRIDGE->SetupAttachment(RootComponent);
	WATER_SHINE->SetupAttachment(RootComponent);
	LOGO->SetupAttachment(RootComponent);

	//LogoRenderer->CreateAnimation("Idle", "Aurea_Idle.png", 2, 4, 0.15f);
	//USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Idle");
	//Animation->IsAutoScale = true;
	//Animation->AutoScaleRatio = 4.0f;
	//LogoRenderer->ChangeAnimation("Idle");
};

ATitleScene::~ATitleScene()
{
};

void ATitleScene::BeginPlay()
{
	AActor::BeginPlay();
}

void ATitleScene::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ATitleScene::SetLocation_Window(const std::shared_ptr<USpriteRenderer> _Renderer, const FVector _Value)
{
	FVector Location = -(HALF_WINDOW_SIZE) + _Value;

	_Renderer->SetWorldLocation({ Location.X, -Location.Y });
}