#include "PreCompile.h"
#include "Player.h"

#include "GlobalVar.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>


APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	//////////////////////////////////////////////////////////////////////////////////// 郡府 IDLE
	ELLIE = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_LEFT",    "Ellie_Basic_Idle.png",  3,  6, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT",         "Ellie_Basic_Idle.png",  7, 10, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_RIGHT",   "Ellie_Basic_Idle.png", 11, 14, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_LEFT",     "Ellie_Basic_Idle.png", 15, 18, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK",          "Ellie_Basic_Idle.png", 19, 22, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_RIGHT",    "Ellie_Basic_Idle.png", 23, 26, ELLIE_ANIMDEFAULT_SPEED);

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT IDLE
	ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT",  "Ellie_Basic_Idle.png", { 27, 28, 28, 29 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT",       "Ellie_Basic_Idle.png", { 30, 31, 32, 33 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", { 34, 35, 35, 36 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT",   "Ellie_Basic_Idle.png", { 37, 38, 38, 37 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT",  "Ellie_Basic_Idle.png", { 39, 40, 40, 39 }, { ELLIE_ANIMDEFAULT_SPEED });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 SHADOW IDLE
	ELLIE_SHADOW = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_SHADOW->SetSprite("Ellie_Basic_Idle.png", 1);
	ELLIE_SHADOW->SetRelativeScale3D({ 140, 140, 0 });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 WALK
	ELLIE->CreateAnimation("ELLIE_WALK_UP",       "Ellie_Basic_Walk.png", 77, 84, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_WALK_DOWN",     "Ellie_Basic_Walk.png", 41, 48, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_WALK_LEFT",     "Ellie_Basic_Walk.png", 33, 40, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_WALK_LEFT_UP",  "Ellie_Basic_Walk.png", 65, 72, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_WALK_RIGHT",    "Ellie_Basic_Walk.png", 53, 60, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE->CreateAnimation("ELLIE_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 89, 97, ELLIE_ANIMDEFAULT_SPEED);

	////////////////////////////////////////////////////////////////////////////////////
	// 	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT WALK
	ELLIE_HAT->CreateAnimation("HAT_WALK_DOWN",     "Ellie_Basic_Walk.png", { 109, 110, 128, 128, 109, 110, 128, 128 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT",     "Ellie_Basic_Walk.png", { 107, 108, 99, 99, 107, 108, 99, 99 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT_UP",  "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
	ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT",    "Ellie_Basic_Walk.png", { 114, 115, 116, 116, 114, 115, 116, 116 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);

	////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////// 郡府 RUN
	ELLIE->CreateAnimation("ELLIE_RUN_UP",       "Ellie_Basic_Run.png", { 29, 30, 31, 32, 33, 34 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE->CreateAnimation("ELLIE_RUN_DOWN",     "Ellie_Basic_Run.png", { 9, 10, 11, 12, 13, 14 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE->CreateAnimation("ELLIE_RUN_LEFT",     "Ellie_Basic_Run.png", { 3, 4, 5, 6, 7, 8 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE->CreateAnimation("ELLIE_RUN_LEFT_UP",  "Ellie_Basic_Run.png", { 23, 24, 25, 23, 26, 27 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE->CreateAnimation("ELLIE_RUN_RIGHT",    "Ellie_Basic_Run.png", { 16, 17, 18, 19, 20, 21 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE->CreateAnimation("ELLIE_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 36, 37, 38, 36, 39, 40 }, { ELLIE_ANIMDEFAULT_SPEED });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT RUN
	ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT",     "Ellie_Basic_Run.png", { 41, 42, 43, 41, 44, 45 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_RUN_DOWN",     "Ellie_Basic_Run.png", { 46, 47, 47, 46, 48, 48 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT_UP",  "Ellie_Basic_Run.png", { 56, 57, 58, 56, 59, 60 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT",    "Ellie_Basic_Run.png", { 50, 51, 52, 50, 53, 54 }, { ELLIE_ANIMDEFAULT_SPEED });
	ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 62, 63, 64, 62, 65, 66 }, { ELLIE_ANIMDEFAULT_SPEED });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 SHADOW RUN
	ELLIE_SHADOW->CreateAnimation("ELLIE_RUN_SHADOW", "Ellie_Basic_Run.png", 0, 2, ELLIE_ANIMDEFAULT_SPEED);

	////////////////////////////////////////////////////////////////////////////////////

	AUREA = CreateDefaultSubObject<USpriteRenderer>();
	AUREA->CreateAnimation("AUREA_IDLE_LEFT", "Aurea_Idle.png", 0, 3, 0.15f);

	ELLIE_SHADOW->ChangeAnimation("ELLIE_RUN_SHADOW");
	ELLIE_SHADOW->SetAutoScale(true);
	ELLIE->ChangeAnimation("ELLIE_WALK_LEFT");
	ELLIE->SetAutoScale(true);
	ELLIE_HAT->ChangeAnimation("HAT_WALK_LEFT");
	ELLIE_HAT->SetAutoScale(true);
	AUREA->ChangeAnimation("AUREA_IDLE_LEFT");
	AUREA->SetAutoScale(true);

	ELLIE_SHADOW->SetRelativeLocation({ 200,0,0 });
	ELLIE->SetRelativeLocation({ 200,0,0 });
	ELLIE_HAT->SetRelativeLocation({ 200,0,0 });
	AUREA->SetRelativeLocation({ -200,0,0 });

	ELLIE_SHADOW->SetupAttachment(RootComponent);
	ELLIE->SetupAttachment(RootComponent);
	ELLIE_HAT->SetupAttachment(RootComponent);
	AUREA->SetupAttachment(RootComponent);
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
