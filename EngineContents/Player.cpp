#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>


APlayer::APlayer()
{
	Player = CreateDefaultSubObject<USpriteRenderer>();
	Player->SetSprite("Aurea_Idle.png", 1);
	Player->SetRelativeScale3D({ 50.0f, 50.0f, 1.0f });
	Player->SetRelativeLocation({ 0, 0, 0 });
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
}
