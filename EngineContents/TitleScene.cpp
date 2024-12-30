#include "PreCompile.h"
#include "TitleScene.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "GlobalVar.h"

ATitleScene::ATitleScene()
{
	BG_SKY = CreateDefaultSubObject<USpriteRenderer>();
	BG_SKY->SetSprite("Title_Train_Sky.png", 0);
	BG_SKY->SetRelativeScale3D({ 1280.0f, 720.0f, 1.0f });
	SetLocation_Window(BG_SKY, { 0,0,0 });

	BG_WATER = CreateDefaultSubObject<USpriteRenderer>();
	BG_WATER->SetSprite("Title_Train_Water.png", 0);
	BG_WATER->SetRelativeScale3D({ 1280.0f, 195.0f, 1.0f });
	SetLocation_Window(BG_WATER, { 0, 525.0f, 0 });

	SKY_MOON = CreateDefaultSubObject<USpriteRenderer>();
	SKY_MOON->SetSprite("Title_Train_Moon.png", 0);
	SKY_MOON->SetRelativeScale3D({ 171.0f, 171.0f, 1.0f });
	SetLocation_Window(SKY_MOON, { 229.0f, 66.0f, 0 });

	LOGO = CreateDefaultSubObject<USpriteRenderer>();
	LOGO->SetSprite("Logo.png", 0);
	LOGO->SetRelativeScale3D({ 451.0f, 220.0f, 1.0f });
	SetLocation_Window(LOGO, {817.0f, 116.0f, 0});





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