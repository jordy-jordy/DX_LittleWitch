#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>


APlayer::APlayer()
{
	//std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	//RootComponent = Default;

	ELLIE = CreateDefaultSubObject<USpriteRenderer>();
	////////////////////////////////////////////////////////////////////// ¿¤¸® IDLE
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_LEFT",  "Ellie_Basic_Idle.png",  3,  6, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT",       "Ellie_Basic_Idle.png",  7, 10, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", 11, 14, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_LEFT",   "Ellie_Basic_Idle.png", 15, 18, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK",        "Ellie_Basic_Idle.png", 19, 22, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_RIGHT",  "Ellie_Basic_Idle.png", 23, 26, 0.2f);

	////////////////////////////////////////////////////////////////////// ¿¤¸® HAT IDLE
	ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT",  "Ellie_Basic_Idle.png", 27, 29, 0.1f);
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT",       "Ellie_Basic_Idle.png", 30, 33, 0.1f);
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", 34, 36, 0.1f);
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT",   "Ellie_Basic_Idle.png", 37, 38, 0.1f);
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT",  "Ellie_Basic_Idle.png", 39, 40, 0.1f);

	////////////////////////////////////////////////////////////////////// ¿¤¸® SHADOW IDLE


	AUREA = CreateDefaultSubObject<USpriteRenderer>();
	AUREA->CreateAnimation("AUREA_IDLE_LEFT", "Aurea_Idle.png", 0, 3, 0.15f);

	//ELLIE->ChangeAnimation("ELLIE_IDLE_FRONT_LEFT");
	ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT_LEFT");
	AUREA->ChangeAnimation("AUREA_IDLE_LEFT");

	//ELLIE->SetRelativeLocation({ 200,0,0 });
	ELLIE_HAT->SetRelativeLocation({ 200,0,0 });
	AUREA->SetRelativeLocation({ -200,0,0 });
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

	//if (UEngineInput::IsPress('A'))
	//{
	//	ELLIE->ChangeAnimation("WALK_LEFT");
	//}

}
