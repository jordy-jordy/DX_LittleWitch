#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/CameraActor.h>

#include "GlobalVar.h"


APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	ELLIE = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>();
	ELLIE_SHADOW = CreateDefaultSubObject<USpriteRenderer>();

	/***** ¿¤¸® - IDLE - Ä³¸¯ÅÍ *****/
	{
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_LEFT", "Ellie_Basic_Idle.png", 3, 6, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT", "Ellie_Basic_Idle.png", 7, 10, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", 11, 14, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK_LEFT", "Ellie_Basic_Idle.png", 15, 18, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK", "Ellie_Basic_Idle.png", 19, 22, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK_RIGHT", "Ellie_Basic_Idle.png", 23, 26, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ¿¤¸® - IDLE - ¸ðÀÚ   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT", "Ellie_Basic_Idle.png", { 27, 28, 28, 29 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT", "Ellie_Basic_Idle.png", { 30, 31, 32, 33 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", { 34, 35, 35, 36 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT", "Ellie_Basic_Idle.png", { 37, 38, 38, 37 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT", "Ellie_Basic_Idle.png", { 39, 40, 40, 39 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ¿¤¸® - IDLE - ±×¸²ÀÚ *****/
	{
		ELLIE_SHADOW->SetSprite("Ellie_Basic_Idle.png", 1);
		ELLIE_SHADOW->SetRelativeScale3D({ 140, 140, 0 });
	}

	/***** ¿¤¸® - WALK - Ä³¸¯ÅÍ *****/
	{
		ELLIE->CreateAnimation("ELLIE_WALK_UP", "Ellie_Basic_Walk.png", 77, 84, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_DOWN", "Ellie_Basic_Walk.png", 41, 48, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT", "Ellie_Basic_Walk.png", 33, 40, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 65, 72, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT", "Ellie_Basic_Walk.png", 53, 60, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 89, 97, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ¿¤¸® - WALK - ¸ðÀÚ   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_WALK_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_DOWN", "Ellie_Basic_Walk.png", { 109, 110, 128, 128, 109, 110, 128, 128 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT", "Ellie_Basic_Walk.png", { 107, 108, 99, 99, 107, 108, 99, 99 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT", "Ellie_Basic_Walk.png", { 114, 115, 116, 116, 114, 115, 116, 116 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ¿¤¸® - RUN  - Ä³¸¯ÅÍ *****/
	{
		ELLIE->CreateAnimation("ELLIE_RUN_UP", "Ellie_Basic_Run.png", { 29, 30, 31, 32, 33, 34 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_DOWN", "Ellie_Basic_Run.png", { 9, 10, 11, 12, 13, 14 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT", "Ellie_Basic_Run.png", { 3, 4, 5, 6, 7, 8 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 23, 24, 25, 23, 26, 27 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT", "Ellie_Basic_Run.png", { 16, 17, 18, 19, 20, 21 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 36, 37, 38, 36, 39, 40 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ¿¤¸® - RUN  - ¸ðÀÚ   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_RUN_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_RUN_DOWN", "Ellie_Basic_Run.png", { 46, 47, 47, 46, 48, 48 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT", "Ellie_Basic_Run.png", { 41, 42, 43, 41, 44, 45 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 56, 57, 58, 56, 59, 60 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT", "Ellie_Basic_Run.png", { 50, 51, 52, 50, 53, 54 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 62, 63, 64, 62, 65, 66 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ¿¤¸® - RUN  - ±×¸²ÀÚ *****/
	{
		ELLIE_SHADOW->CreateAnimation("ELLIE_RUN_SHADOW", "Ellie_Basic_Run.png", 0, 2, ELLIE_ANIMDEFAULT_SPEED);
	}

	ELLIE->ChangeAnimation("ELLIE_IDLE_FRONT");
	ELLIE->SetAutoScale(true);
	ELLIE->SetRelativeLocation({ 0, 0, 0 });
	ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT");
	ELLIE_HAT->SetAutoScale(true);
	ELLIE_HAT->SetRelativeLocation({ 0, 0, -1 });

	ELLIE_Coll = CreateDefaultSubObject<UCollision>();
	ELLIE_Coll->SetCollisionProfileName("Player");
	ELLIE_Coll->SetWorldLocation({ 0, 70, 0 });
	ELLIE_Coll->SetScale3D({10, 10, 1});
	
	//ELLIE_SHADOW->SetupAttachment(RootComponent);
	ELLIE_Coll->SetupAttachment(RootComponent);
	ELLIE->SetupAttachment(RootComponent);
	ELLIE_HAT->SetupAttachment(RootComponent);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(this->GetActorLocation());
	Camera->GetCameraComponent()->SetFar(10000);
	Camera->GetCameraComponent()->SetNear(-100);
	Camera->GetCameraComponent()->SetZSort(0, false);
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

	switch (CurrentState)
	{
	case EllieState::State::IDLE:
		EllieIDLE(_DeltaTime);
		break;

	case EllieState::State::WALK:
		EllieWALK(_DeltaTime);
		break;

	case EllieState::State::RUN:
		EllieRUN(_DeltaTime);
		break;
	default:
		break;
	}
}

bool APlayer::CheckIsInField()
{
	std::vector<UCollision*> Result;
	if (true == ELLIE_Coll->CollisionCheck("Field", Result))
	{
		return IsInField = true;
	}
	else if (false == ELLIE_Coll->CollisionCheck("Field", Result))
	{
		return IsInField = false;
	}
	return true;
}

void APlayer::ChangeState(EllieState::State _CurPlayerState)
{
	switch (_CurPlayerState)
	{
	case EllieState::State::IDLE:
		break;
	case EllieState::State::WALK:
		break;
	case EllieState::State::RUN:
		break;
	default:
		break;
	}

	CurrentState = _CurPlayerState;
}

void APlayer::EllieIDLE(float _DeltaTime)
{
	if (CurrentWALKState == EllieState::EllieWALK_Vector::WALK_UP)
	{
		CurrentIDLEState = EllieState::EllieIDLE_Vector::IDLE_BACK;
	}
	else if (CurrentWALKState == EllieState::EllieWALK_Vector::WALK_DOWN)
	{
		CurrentIDLEState = EllieState::EllieIDLE_Vector::IDLE_FRONT;
	}
	else if (CurrentWALKState == EllieState::EllieWALK_Vector::WALK_LEFT)
	{
		CurrentIDLEState = EllieState::EllieIDLE_Vector::IDLE_FRONT_LEFT;
	}
	else if (CurrentWALKState == EllieState::EllieWALK_Vector::WALK_RIGHT)
	{
		CurrentIDLEState = EllieState::EllieIDLE_Vector::IDLE_FRONT_RIGHT;
	}
	else
	{
		CurrentIDLEState = EllieState::EllieIDLE_Vector::IDLE_FRONT;
	}

	switch (CurrentIDLEState)
	{
	case EllieState::EllieIDLE_Vector::IDLE_FRONT_LEFT:
		ELLIE->ChangeAnimation("ELLIE_IDLE_FRONT_LEFT");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT_LEFT");
		break;

	case EllieState::EllieIDLE_Vector::IDLE_FRONT:
		ELLIE->ChangeAnimation("ELLIE_IDLE_FRONT");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT");
		break;

	case EllieState::EllieIDLE_Vector::IDLE_FRONT_RIGHT:
		ELLIE->ChangeAnimation("ELLIE_IDLE_FRONT_RIGHT");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT_RIGHT");
		break;

	case EllieState::EllieIDLE_Vector::IDLE_BACK_LEFT:
		ELLIE->ChangeAnimation("ELLIE_IDLE_BACK_LEFT");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_BACK_LEFT");
		break;

	case EllieState::EllieIDLE_Vector::IDLE_BACK:
		ELLIE->ChangeAnimation("ELLIE_IDLE_BACK");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_BACK");
		break;

	case EllieState::EllieIDLE_Vector::IDLE_BACK_RIGHT:
		ELLIE->ChangeAnimation("ELLIE_IDLE_BACK_RIGHT");
		ELLIE_HAT->ChangeAnimation("HAT_IDLE_BACK_RIGHT");
		break;
	}

	if (true == UEngineInput::IsPress('A') ||
		true == UEngineInput::IsPress('D') ||
		true == UEngineInput::IsPress('W') ||
		true == UEngineInput::IsPress('S'))
	{
		ChangeState(EllieState::State::WALK);
		return;
	}
}

void APlayer::EllieWALK(float _DeltaTime)
{
	if (UEngineInput::IsPress('A'))
	{
		CurrentWALKState = EllieState::EllieWALK_Vector::WALK_LEFT;
	}
	if (UEngineInput::IsPress('W'))
	{
		CurrentWALKState = EllieState::EllieWALK_Vector::WALK_UP;
	}
	if (UEngineInput::IsPress('D'))
	{
		CurrentWALKState = EllieState::EllieWALK_Vector::WALK_RIGHT;
	}
	if (UEngineInput::IsPress('S'))
	{
		CurrentWALKState = EllieState::EllieWALK_Vector::WALK_DOWN;
	}

	FVector NEXTPOS_UP = VECTOR_UP * ELLIE_WALK_SPEED * _DeltaTime;
	FVector NEXTPOS_DOWN = VECTOR_DOWN * ELLIE_WALK_SPEED * _DeltaTime;
	FVector NEXTPOS_LEFT = VECTOR_LEFT * ELLIE_WALK_SPEED * _DeltaTime;
	FVector NEXTPOS_RIGHT = VECTOR_RIGHT * ELLIE_WALK_SPEED * _DeltaTime;

	std::vector<UCollision*> Result;
	switch (CurrentWALKState)
	{
	case EllieState::EllieWALK_Vector::WALK_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_UP");
		if (false != ELLIE_Coll->CollisionCheck("Field", NEXTPOS_UP, Result))
		{
			Camera->AddActorLocation(NEXTPOS_UP);
			AddActorLocation(NEXTPOS_UP);
		}
		break;

	case EllieState::EllieWALK_Vector::WALK_DOWN:
		ELLIE->ChangeAnimation("ELLIE_WALK_DOWN");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_DOWN");
		if (false != ELLIE_Coll->CollisionCheck("Field", NEXTPOS_DOWN, Result))
		{
			Camera->AddActorLocation(NEXTPOS_DOWN);
			AddActorLocation(NEXTPOS_DOWN);
		}
		break;

	case EllieState::EllieWALK_Vector::WALK_LEFT:
		ELLIE->ChangeAnimation("ELLIE_WALK_LEFT");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_LEFT");
		if (false != ELLIE_Coll->CollisionCheck("Field", NEXTPOS_LEFT, Result))
		{
			Camera->AddActorLocation(NEXTPOS_LEFT);
			AddActorLocation(NEXTPOS_LEFT);
		}
		break;

	case EllieState::EllieWALK_Vector::WALK_LEFT_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_LEFT_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_LEFT_UP");
		AddRelativeLocation(VECTOR_LEFT_UP * ELLIE_WALK_SPEED * _DeltaTime);
		break;

	case EllieState::EllieWALK_Vector::WALK_RIGHT:
		ELLIE->ChangeAnimation("ELLIE_WALK_RIGHT");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_RIGHT");
		if (false != ELLIE_Coll->CollisionCheck("Field", NEXTPOS_RIGHT, Result))
		{
			Camera->AddActorLocation(NEXTPOS_RIGHT);
			AddActorLocation(NEXTPOS_RIGHT);
		}
		break;


	case EllieState::EllieWALK_Vector::WALK_RIGHT_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_RIGHT_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_RIGHT_UP");
		AddRelativeLocation(VECTOR_RIGHT_UP * ELLIE_WALK_SPEED * _DeltaTime);
		break;
	}

	if (true == UEngineInput::IsUp('A') ||
		true == UEngineInput::IsUp('D') ||
		true == UEngineInput::IsUp('W') ||
		true == UEngineInput::IsUp('S'))
	{
		ChangeState(EllieState::State::IDLE);
		return;
	}

}

void APlayer::EllieRUN(float _DeltaTime)
{
	switch (CurrentRUNState)
	{
	case EllieState::EllieRUN_Vector::RUN_UP:
		ELLIE->ChangeAnimation("ELLIE_RUN_UP");
		ELLIE_HAT->SetActive(false);
		break;

	case EllieState::EllieRUN_Vector::RUN_DOWN:
		ELLIE->ChangeAnimation("ELLIE_RUN_DOWN");
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation("HAT_RUN_DOWN");
		break;

	case EllieState::EllieRUN_Vector::RUN_LEFT:
		ELLIE->ChangeAnimation("ELLIE_RUN_LEFT");
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation("HAT_RUN_LEFT");
		break;

	case EllieState::EllieRUN_Vector::RUN_LEFT_UP:
		ELLIE->ChangeAnimation("ELLIE_RUN_LEFT_UP");
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation("HAT_RUN_LEFT_UP");
		break;

	case EllieState::EllieRUN_Vector::RUN_RIGHT:
		ELLIE->ChangeAnimation("ELLIE_RUN_RIGHT");
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation("HAT_RUN_RIGHT");
		break;

	case EllieState::EllieRUN_Vector::RUN_RIGHT_UP:
		ELLIE->ChangeAnimation("ELLIE_RUN_RIGHT_UP");
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation("HAT_RUN_RIGHT_UP");
		break;
	}
}