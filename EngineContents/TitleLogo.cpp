#include "PreCompile.h"
#include "TitleLogo.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

ATitleLogo::ATitleLogo()
{
	// 랜더러를 만든다.
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetSprite("Aurea_Idle.png", 1);
	LogoRenderer->SetRelativeScale3D({ 500, 500, 1.0f });

	LogoRenderer->CreateAnimation("Idle", "Aurea_Idle.png", 2, 4, 0.15f);
	USpriteRenderer::FrameAnimation* Animation = LogoRenderer->FindAnimation("Idle");
	Animation->IsAutoScale = true;
	Animation->AutoScaleRatio = 4.0f;
	LogoRenderer->ChangeAnimation("Idle");
}

ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	AActor::BeginPlay();
}

void ATitleLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// AddActorLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f});
}