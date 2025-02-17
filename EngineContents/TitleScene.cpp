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

	BG_SKY = CreateDefaultSubObject<USpriteRenderer>().get();
	BG_SKY->SetSprite("Title_Train_Sky.png", 0);
	BG_SKY->SetRelativeScale3D({ 1280.0f, 720.0f, 1.0f });
	SetLocation_Window(BG_SKY, { 0, 0, 8900.0f });

	SKY_STAR = CreateDefaultSubObject<USpriteRenderer>().get();
	SKY_STAR->SetAutoScale(false);
	SKY_STAR->SetSprite("Title_train_star.png", 0);
	SKY_STAR->CreateAnimation("STARS", "Title_train_star.png", 0, 4, 0.15f);
	SKY_STAR->SetRelativeScale3D({ 1275.0f, 352.0f, 1.0f });
	SetLocation_Window(SKY_STAR, { 0.0f, 0.0f, 8800.0f });
	SKY_STAR->ChangeAnimation("STARS");

	SKY_MOON = CreateDefaultSubObject<USpriteRenderer>().get();
	SKY_MOON->SetSprite("Title_Train_Moon.png", 0);
	SKY_MOON->SetRelativeScale3D({ 171.0f, 171.0f, 1.0f });
	SetLocation_Window(SKY_MOON, { 229.0f, 66.0f, 8000.0f });

	CLOUD_FAR = CreateDefaultSubObject<USpriteRenderer>().get();
	CLOUD_FAR->SetSprite("CLOUD_FAR.png", 0);
	CLOUD_FAR->SetRelativeScale3D({ 2142.0f, 720.0f, 1.0f });
	SetLocation_Window(CLOUD_FAR, { 0.0f, 0.0f, 7000.0f });

	CLOUD_MID = CreateDefaultSubObject<USpriteRenderer>().get();
	CLOUD_MID->SetSprite("CLOUD_MIDDLE.png", 0);
	CLOUD_MID->SetRelativeScale3D({ 2142.0f, 720.0f, 1.0f });
	SetLocation_Window(CLOUD_MID, { 0.0f, 0.0f, 6500.0f });

	CLOUD_NEAR = CreateDefaultSubObject<USpriteRenderer>().get();
	CLOUD_NEAR->SetSprite("CLOUD_NEAR.png", 0);
	CLOUD_NEAR->SetRelativeScale3D({ 2142.0f, 720.0f, 1.0f });
	SetLocation_Window(CLOUD_NEAR, { 0.0f, 0.0f, 6000.0f });

	BG_WATER = CreateDefaultSubObject<USpriteRenderer>().get();
	BG_WATER->SetSprite("Title_Train_Water.png", 0);
	BG_WATER->SetRelativeScale3D({ 1280.0f, 195.0f, 1.0f });
	SetLocation_Window(BG_WATER, { 0, 525.0f, 950.0f });

	MOUNTAIN = CreateDefaultSubObject<USpriteRenderer>().get();
	MOUNTAIN->SetSprite("Title_Train_Mountain.png", 0);
	MOUNTAIN->SetRelativeScale3D({ 1315.0f, 304.0f, 1.0f });
	SetLocation_Window(MOUNTAIN, { 0.0f, 216.0f, 900.0f });

	TRAIN_SHADOW = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN_SHADOW->SetSprite("Title_Train_TrainWater_blur.png", 0);
	TRAIN_SHADOW->SetRelativeScale3D({ 870.0f, 53.0f, 1.0f });
	SetLocation_Window(TRAIN_SHADOW, { 0.0f, 658.0f, 830.0f });

	MOUNTAIN_SHADOW = CreateDefaultSubObject<USpriteRenderer>().get();
	MOUNTAIN_SHADOW->SetSprite("Title_Train_MountainWater_blur.png", 0);
	MOUNTAIN_SHADOW->SetRelativeScale3D({ 1297.0f, 222.0f, 1.0f });
	SetLocation_Window(MOUNTAIN_SHADOW, { 0.0f, 520.0f, 820.0f });

	TRAIN0 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN0->SetSprite("Title_Train_Train_0.png", 0);
	TRAIN0->SetRelativeScale3D({ 259.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN0, { 615.0f, 431.0f, 800.0f });

	TRAIN1 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN1->SetSprite("Title_Train_Train_1.png", 0);
	TRAIN1->SetRelativeScale3D({ 152.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN1, { 466.0f, 431.0f, 800.0f });

	TRAIN2 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN2->SetSprite("Title_Train_Train_1.png", 0);
	TRAIN2->SetRelativeScale3D({ 152.0f, 72.0f, 1.0f });
	SetLocation_Window(TRAIN2, { 317.0f, 431.0f, 800.0f });

	TRAIN3 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN3->SetSprite("Title_Train_Train_3.png", 0);
	TRAIN3->SetRelativeScale3D({ 299.0f, 70.0f, 1.0f });
	SetLocation_Window(TRAIN3, { 21.0f, 432.0f, 800.0f });

	TRAIN4 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN4->SetSprite("Title_Train_Train_3.png", 0);
	TRAIN4->SetRelativeScale3D({ 299.0f, 70.0f, 1.0f });
	SetLocation_Window(TRAIN4, { -275.0f, 432.0f, 800.0f });

	TRAIN0_LIGHT = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN0_LIGHT->SetSprite("Title_Train_Window_0.png", 0);
	TRAIN0_LIGHT->SetRelativeScale3D({ 172.0f, 28.0f, 1.0f });
	SetLocation_Window(TRAIN0_LIGHT, { 631.0f, 455.0f, 790.0f });

	TRAIN1_LIGHT = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN1_LIGHT->SetSprite("Title_Train_Window_1.png", 0);
	TRAIN1_LIGHT->SetRelativeScale3D({ 142.0f, 36.0f, 1.0f });
	SetLocation_Window(TRAIN1_LIGHT, { 473.0f, 449.0f, 790.0f });

	TRAIN2_LIGHT = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN2_LIGHT->SetSprite("Title_Train_Window_1.png", 0);
	TRAIN2_LIGHT->SetRelativeScale3D({ 142.0f, 36.0f, 1.0f });
	SetLocation_Window(TRAIN2_LIGHT, { 325.0f, 449.0f, 790.0f });

	TRAIN3_LIGHT = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN3_LIGHT->SetSprite("Title_Train_Light.png", 0);
	TRAIN3_LIGHT->SetRelativeScale3D({ 221.0f, 17.0f, 1.0f });
	SetLocation_Window(TRAIN3_LIGHT, { 67.0f, 467.0f, 790.0f });

	BRIDGE_SHADOW1 = CreateDefaultSubObject<USpriteRenderer>().get();
	BRIDGE_SHADOW1->SetSprite("Title_Train_Bridge_Down.png", 0);
	BRIDGE_SHADOW1->SetRelativeScale3D({ 1404.0f, 58.0f, 1.0f });
	SetLocation_Window(BRIDGE_SHADOW1, { -62.0f, 630.0f, 790.0f });

	WATER_GLARE = CreateDefaultSubObject<USpriteRenderer>().get();
	WATER_GLARE->SetSprite("Title_Train_WaterShine_blur.png", 0);
	WATER_GLARE->SetRelativeScale3D({ 1335.0f, 180.0f, 1.0f });
	SetLocation_Window(WATER_GLARE, { -29.0f, 563.0f, 780.0f });

	//BRIDGE_SHADOW0 = CreateDefaultSubObject<USpriteRenderer>();
	//BRIDGE_SHADOW0->SetSprite("Title_Train_Bridge_Shadow.png", 0);
	//BRIDGE_SHADOW0->SetRelativeScale3D({ 1300.0f, 81.0f, 1.0f });
	//SetLocation_Window(BRIDGE_SHADOW0, { -10.0f, 595.0f, 770.0f });

	TRAIN_LIGHT_BLUR0 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN_LIGHT_BLUR0->SetSprite("Title_Train_WindowWater_blur.png", 0);
	TRAIN_LIGHT_BLUR0->SetRelativeScale3D({ 540.0f, 69.0f, 1.0f });
	SetLocation_Window(TRAIN_LIGHT_BLUR0, { 292.0f, 645.0f, 760.0f });

	TRAIN_LIGHT_BLUR1 = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN_LIGHT_BLUR1->SetSprite("Title_Train_Light_Blur.png", 0);
	TRAIN_LIGHT_BLUR1->SetRelativeScale3D({ 287.0f, 39.0f, 1.0f });
	SetLocation_Window(TRAIN_LIGHT_BLUR1, { 21.0f, 656.0f, 760.0f });

	TRAIN_BRIDGE = CreateDefaultSubObject<USpriteRenderer>().get();
	TRAIN_BRIDGE->SetSprite("Title_Train_Bridge.png", 0);
	TRAIN_BRIDGE->SetRelativeScale3D({ 1404.0f, 133.0f, 1.0f });
	SetLocation_Window(TRAIN_BRIDGE, { -62.0f, 502.0f, 760.0f });

	WATER_SHINE = CreateDefaultSubObject<USpriteRenderer>().get();
	WATER_SHINE->SetSprite("Title_Train_WaterShine.png", 0);
	WATER_SHINE->SetRelativeScale3D({ 1404.0f, 4.0f, 1.0f });
	SetLocation_Window(WATER_SHINE, { -62.0f, 635.0f, 750.0f });

	TREE_0 = CreateDefaultSubObject<USpriteRenderer>().get();
	TREE_0->SetSprite("Title_Train_Tree_0.png", 0);
	TREE_0->SetAutoScaleRatio(1.0f);
	SetLocation_Window(TREE_0, { 0.0f, 340.0f, 500.0f });

	TREE_1 = CreateDefaultSubObject<USpriteRenderer>().get();
	TREE_1->SetSprite("Title_Train_Tree_1.png", 0);
	TREE_1->SetAutoScaleRatio(1.0f);
	SetLocation_Window(TREE_1, { 0.0f, 360.0f, 450.0f });

	LOGO = CreateDefaultSubObject<USpriteRenderer>().get();
	LOGO->SetSprite("Logo.png", 0);
	LOGO->SetRelativeScale3D({ 451.0f, 220.0f, 1.0f });
	SetLocation_Window(LOGO, { 817.0f, 116.0f, 0.0f });

	BG_SKY->SetAutoScale(false);
	SKY_MOON->SetAutoScale(false);
	CLOUD_FAR->SetAutoScale(false);
	CLOUD_MID->SetAutoScale(false);
	CLOUD_NEAR->SetAutoScale(false);
	BG_WATER->SetAutoScale(false);
	MOUNTAIN->SetAutoScale(false);
	TRAIN_SHADOW->SetAutoScale(false);
	MOUNTAIN_SHADOW->SetAutoScale(false);
	TRAIN0->SetAutoScale(false);
	TRAIN1->SetAutoScale(false);
	TRAIN2->SetAutoScale(false);
	TRAIN3->SetAutoScale(false);
	TRAIN4->SetAutoScale(false);
	TRAIN0_LIGHT->SetAutoScale(false);
	TRAIN1_LIGHT->SetAutoScale(false);
	TRAIN2_LIGHT->SetAutoScale(false);
	TRAIN3_LIGHT->SetAutoScale(false);
	BRIDGE_SHADOW1->SetAutoScale(false);
	WATER_GLARE->SetAutoScale(false);
	TRAIN_LIGHT_BLUR0->SetAutoScale(false);
	TRAIN_LIGHT_BLUR1->SetAutoScale(false);
	TRAIN_BRIDGE->SetAutoScale(false);
	WATER_SHINE->SetAutoScale(false);
	TREE_0->SetAutoScale(true);
	TREE_1->SetAutoScale(true);
	LOGO->SetAutoScale(false);

	BG_SKY->SetupAttachment(RootComponent);
	SKY_STAR->SetupAttachment(RootComponent);
	SKY_MOON->SetupAttachment(RootComponent);
	CLOUD_FAR->SetupAttachment(RootComponent);
	CLOUD_MID->SetupAttachment(RootComponent);
	CLOUD_NEAR->SetupAttachment(RootComponent);
	BG_WATER->SetupAttachment(RootComponent);
	MOUNTAIN->SetupAttachment(RootComponent);
	TRAIN_SHADOW->SetupAttachment(RootComponent);
	MOUNTAIN_SHADOW->SetupAttachment(RootComponent);
	TRAIN0->SetupAttachment(RootComponent);
	TRAIN1->SetupAttachment(RootComponent);
	TRAIN2->SetupAttachment(RootComponent);
	TRAIN3->SetupAttachment(RootComponent);
	TRAIN4->SetupAttachment(RootComponent);
	TRAIN0_LIGHT->SetupAttachment(RootComponent);
	TRAIN1_LIGHT->SetupAttachment(RootComponent);
	TRAIN2_LIGHT->SetupAttachment(RootComponent);
	TRAIN3_LIGHT->SetupAttachment(RootComponent);
	BRIDGE_SHADOW1->SetupAttachment(RootComponent);
	WATER_GLARE->SetupAttachment(RootComponent);
	TRAIN_LIGHT_BLUR0->SetupAttachment(RootComponent);
	TRAIN_LIGHT_BLUR1->SetupAttachment(RootComponent);
	TRAIN_BRIDGE->SetupAttachment(RootComponent);
	//BRIDGE_SHADOW0->SetupAttachment(RootComponent);
	WATER_SHINE->SetupAttachment(RootComponent);
	TREE_0->SetupAttachment(RootComponent);
	TREE_1->SetupAttachment(RootComponent);
	LOGO->SetupAttachment(RootComponent);
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

	float SPEED_Far = 0.3f;
	float SPEED_Mid = 0.5f;
	float SPEED_Near = 0.7f;

	float SPEED_CLOUD_Far = 0.04f;
	float SPEED_CLOUD_Mid = 0.08f;
	float SPEED_CLOUD_Near = 0.12f;

	float SPEED_TREE_Far = 0.75f;
	float SPEED_TREE_Near = 0.8f;

	MOUNTAIN->UVValue.PlusUVValue += (float4{1.0f, 0.0f, 0.0f, 0.0f} * SPEED_Far *_DeltaTime);
	MOUNTAIN_SHADOW->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_Far * _DeltaTime);

	CLOUD_FAR->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_CLOUD_Far * _DeltaTime);
	CLOUD_MID->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_CLOUD_Mid * _DeltaTime);
	CLOUD_NEAR->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_CLOUD_Near * _DeltaTime);

	TRAIN_BRIDGE->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_Near * _DeltaTime);
	BRIDGE_SHADOW1->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_Near * _DeltaTime);
	WATER_GLARE->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_Near * _DeltaTime);
	WATER_SHINE->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_Near * _DeltaTime);

	TREE_0->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_TREE_Far * _DeltaTime);
	TREE_1->UVValue.PlusUVValue += (float4{ 1.0f, 0.0f, 0.0f, 0.0f } * SPEED_TREE_Near * _DeltaTime);
}

void ATitleScene::SetLocation_Window(USpriteRenderer* _Renderer, FVector _Value)
{
	FVector Location = -(HALF_WINDOW_SIZE) + _Value;
	_Renderer->SetWorldLocation({ Location.X, -Location.Y, _Value.Z });
}