#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>


APlayer::APlayer()
{
	//std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	//RootComponent = Default;

	Player = CreateDefaultSubObject<USpriteRenderer>();
	//Player->SetSprite("Ellie_Idle.png", 0);
	Player->CreateAnimation("IDLE_LEFT", "Ellie_Idle.png", 0, 3, 0.15f);
	Player->CreateAnimation("IDLE_FRONT", "Ellie_Idle.png", 4, 7, 0.15f);
	Player->CreateAnimation("IDLE_RIGHT", "Ellie_Idle.png", 8, 11, 0.15f);
	Player->CreateAnimation("IDLE_BACK", "Ellie_Idle.png", 16, 19, 0.15f);

	Player->CreateAnimation("WALK_LEFT", "Ellie_Walk.png", 0, 11, 0.15f);

	Player->CreateAnimation("AUREA_IDLE_RIGHT", "Aurea_Idle.png", 1, 5, 0.15f);

	Player->SetRelativeScale3D({ 100.0f, 100.0f, 1.0f });

	Player->ChangeAnimation("IDLE_FRONT");
	
	//Player->SetupAttachment(RootComponent);
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		Player->ChangeAnimation("WALK_LEFT");
	}

}
