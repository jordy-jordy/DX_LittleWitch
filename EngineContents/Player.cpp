#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>


APlayer::APlayer()
{
	//std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	//RootComponent = Default;

	//////////////////////////////////////////////////////////////////////////////////// 郡府 IDLE
	ELLIE = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_LEFT",    "Ellie_Basic_Idle.png",  3,  6, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT",         "Ellie_Basic_Idle.png",  7, 10, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_RIGHT",   "Ellie_Basic_Idle.png", 11, 14, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_LEFT",     "Ellie_Basic_Idle.png", 15, 18, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK",          "Ellie_Basic_Idle.png", 19, 22, 0.2f);
	ELLIE->CreateAnimation("ELLIE_IDLE_BACK_RIGHT",    "Ellie_Basic_Idle.png", 23, 26, 0.2f);

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT IDLE
	ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT",  "Ellie_Basic_Idle.png", { 27, 28, 28, 29 }, { 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT",       "Ellie_Basic_Idle.png", { 30, 31, 32, 33 }, { 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", { 34, 35, 35, 36 }, { 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT",   "Ellie_Basic_Idle.png", { 37, 38, 38, 37 }, { 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT",  "Ellie_Basic_Idle.png", { 39, 40, 40, 39 }, { 0.2f, 0.2f, 0.2f, 0.2f });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 SHADOW IDLE
	ELLIE_SHADOW = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_SHADOW->SetSprite("Ellie_Basic_Idle.png", 1);
	ELLIE_SHADOW->SetRelativeScale3D({ 140, 140, 0 });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 WALK
	ELLIE->CreateAnimation("ELLIE_WALK_UP",       "Ellie_Basic_Walk.png", 77, 84, 0.2f);
	ELLIE->CreateAnimation("ELLIE_WALK_DOWN",     "Ellie_Basic_Walk.png", 41, 48, 0.2f);
	ELLIE->CreateAnimation("ELLIE_WALK_LEFT",     "Ellie_Basic_Walk.png",  9, 16, 0.2f);
	ELLIE->CreateAnimation("ELLIE_WALK_LEFT_UP",  "Ellie_Basic_Walk.png", 65, 72, 0.2f);
	ELLIE->CreateAnimation("ELLIE_WALK_RIGHT",    "Ellie_Basic_Walk.png", 53, 60, 0.2f);
	ELLIE->CreateAnimation("ELLIE_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 89, 97, 0.2f);

	////////////////////////////////////////////////////////////////////////////////////
	// 	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT WALK
	ELLIE_HAT->CreateAnimation("HAT_WALK_DOWN",     "Ellie_Basic_Walk.png", { 106, 104, 105, 106, 104, 105, 106, 104 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	//ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT",     "Ellie_Basic_Walk.png", { 41, 42, 43, 41, 44, 45 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	//ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT_UP",  "Ellie_Basic_Walk.png", { 56, 57, 58, 56, 59, 60 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	//ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT",    "Ellie_Basic_Walk.png", { 50, 51, 52, 50, 53, 54 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	//ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", { 62, 63, 64, 62, 65, 66 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });

	////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////// 郡府 RUN
	ELLIE->CreateAnimation("ELLIE_RUN_UP",       "Ellie_Basic_Run.png", { /*28,*/ 29, 30, 31, 32, 33, 34 }, { /*0.2f,*/ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE->CreateAnimation("ELLIE_RUN_DOWN",     "Ellie_Basic_Run.png", { 9, 10, 11, 12, 13, 14 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE->CreateAnimation("ELLIE_RUN_LEFT",     "Ellie_Basic_Run.png", { 3, 4, 5, 6, 7, 8 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE->CreateAnimation("ELLIE_RUN_LEFT_UP",  "Ellie_Basic_Run.png", { 23, 24, 25, 23, 26, 27 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE->CreateAnimation("ELLIE_RUN_RIGHT",    "Ellie_Basic_Run.png", { /*15,*/ 16, 17, 18, 19, 20, 21 }, { /*0.2f,*/ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE->CreateAnimation("ELLIE_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 36, 37, 38, 36, 39, 40 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 HAT RUN
	ELLIE_HAT->CreateAnimation("HAT_RUN_DOWN",     "Ellie_Basic_Run.png", { 46, 47, 47, 46, 48, 48 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT",     "Ellie_Basic_Run.png", { 41, 42, 43, 41, 44, 45 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT_UP",  "Ellie_Basic_Run.png", { 56, 57, 58, 56, 59, 60 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT",    "Ellie_Basic_Run.png", { 50, 51, 52, 50, 53, 54 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });
	ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 62, 63, 64, 62, 65, 66 }, { 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f });

	////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////// 郡府 SHADOW RUN
	ELLIE_SHADOW->CreateAnimation("ELLIE_RUN_SHADOW", "Ellie_Basic_Run.png", 0, 2, 0.2f);

	////////////////////////////////////////////////////////////////////////////////////

	AUREA = CreateDefaultSubObject<USpriteRenderer>();
	AUREA->CreateAnimation("AUREA_IDLE_LEFT", "Aurea_Idle.png", 0, 3, 0.15f);

	ELLIE_SHADOW->ChangeAnimation("ELLIE_RUN_SHADOW");
	ELLIE->ChangeAnimation("ELLIE_WALK_DOWN");
	ELLIE_HAT->ChangeAnimation("HAT_WALK_DOWN");
	AUREA->ChangeAnimation("AUREA_IDLE_LEFT");

	ELLIE_SHADOW->SetRelativeLocation({ 200,0,0 });
	ELLIE->SetRelativeLocation({ 200,0,0 });
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
