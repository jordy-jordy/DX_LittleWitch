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

	/***** ���� - IDLE - ĳ���� *****/
	{
		ELLIE = CreateDefaultSubObject<USpriteRenderer>();
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_LEFT", "Ellie_Basic_Idle.png", 3, 6, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT", "Ellie_Basic_Idle.png", 7, 10, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", 11, 14, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK_LEFT", "Ellie_Basic_Idle.png", 15, 18, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK", "Ellie_Basic_Idle.png", 19, 22, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_BACK_RIGHT", "Ellie_Basic_Idle.png", 23, 26, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ���� - IDLE - ����   *****/
	{
		ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>();
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT", "Ellie_Basic_Idle.png", { 27, 28, 28, 29 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT", "Ellie_Basic_Idle.png", { 30, 31, 32, 33 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", { 34, 35, 35, 36 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT", "Ellie_Basic_Idle.png", { 37, 38, 38, 37 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT", "Ellie_Basic_Idle.png", { 39, 40, 40, 39 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ���� - IDLE - �׸��� *****/
	{
		ELLIE_SHADOW = CreateDefaultSubObject<USpriteRenderer>();
		ELLIE_SHADOW->SetSprite("Ellie_Basic_Idle.png", 1);
		ELLIE_SHADOW->SetRelativeScale3D({ 140, 140, 0 });
	}

	/***** ���� - WALK - ĳ���� *****/
	{
		ELLIE->CreateAnimation("ELLIE_WALK_UP", "Ellie_Basic_Walk.png", 77, 84, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_DOWN", "Ellie_Basic_Walk.png", 41, 48, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT", "Ellie_Basic_Walk.png", 33, 40, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 65, 72, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT", "Ellie_Basic_Walk.png", 53, 60, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 89, 97, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ���� - WALK - ����   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_WALK_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_DOWN", "Ellie_Basic_Walk.png", { 109, 110, 128, 128, 109, 110, 128, 128 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT", "Ellie_Basic_Walk.png", { 107, 108, 99, 99, 107, 108, 99, 99 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT", "Ellie_Basic_Walk.png", { 114, 115, 116, 116, 114, 115, 116, 116 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** ���� - RUN  - ĳ���� *****/
	{
		ELLIE->CreateAnimation("ELLIE_RUN_UP", "Ellie_Basic_Run.png", { 29, 30, 31, 32, 33, 34 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_DOWN", "Ellie_Basic_Run.png", { 9, 10, 11, 12, 13, 14 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT", "Ellie_Basic_Run.png", { 3, 4, 5, 6, 7, 8 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 23, 24, 25, 23, 26, 27 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT", "Ellie_Basic_Run.png", { 16, 17, 18, 19, 20, 21 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 36, 37, 38, 36, 39, 40 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ���� - RUN  - ����   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_RUN_UP", "Ellie_Basic_Walk.png", 128, 128, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_RUN_DOWN", "Ellie_Basic_Run.png", { 46, 47, 47, 46, 48, 48 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT", "Ellie_Basic_Run.png", { 41, 42, 43, 41, 44, 45 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 56, 57, 58, 56, 59, 60 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT", "Ellie_Basic_Run.png", { 50, 51, 52, 50, 53, 54 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 62, 63, 64, 62, 65, 66 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** ���� - RUN  - �׸��� *****/
	{
		ELLIE_SHADOW->CreateAnimation("ELLIE_RUN_SHADOW", "Ellie_Basic_Run.png", 0, 2, ELLIE_ANIMDEFAULT_SPEED);
	}

	ELLIE->SetAutoScale(true);
	ELLIE_HAT->SetAutoScale(true);

	//ELLIE_SHADOW->SetRelativeLocation({ 0.0f , 0.0f , 4.0f });
	ELLIE->SetRelativeLocation({ 0.0f , 0.0f , 2.0f });
	ELLIE_HAT->SetRelativeLocation({ 0.0f , 0.0f , 0.0f });

	//ELLIE_SHADOW->SetupAttachment(RootComponent);
	ELLIE->SetupAttachment(RootComponent);
	ELLIE_HAT->SetupAttachment(RootComponent);
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

	switch (CurrentWALKState)
	{
	case EllieState::EllieWALK_Vector::WALK_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_UP");
		ELLIE->AddRelativeLocation(FVector{ 0.0f, 1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f });
		ELLIE_HAT->AddRelativeLocation(FVector{ 0.0f, 1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f });
		break;

	case EllieState::EllieWALK_Vector::WALK_DOWN:
		ELLIE->ChangeAnimation("ELLIE_WALK_DOWN");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_DOWN");
		ELLIE->AddRelativeLocation(FVector{ 0.0f, -1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f });
		ELLIE_HAT->AddRelativeLocation(FVector{ 0.0f, -1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f });
		break;

	case EllieState::EllieWALK_Vector::WALK_LEFT:
		ELLIE->ChangeAnimation("ELLIE_WALK_LEFT");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_LEFT");
		ELLIE->AddRelativeLocation(FVector{ -1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f, 0.0f });
		ELLIE_HAT->AddRelativeLocation(FVector{ -1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f, 0.0f });
		break;

	case EllieState::EllieWALK_Vector::WALK_LEFT_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_LEFT_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_LEFT_UP");
		break;

	case EllieState::EllieWALK_Vector::WALK_RIGHT:
		ELLIE->ChangeAnimation("ELLIE_WALK_RIGHT");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_RIGHT");
		ELLIE->AddRelativeLocation(FVector{ 1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f, 0.0f });
		ELLIE_HAT->AddRelativeLocation(FVector{ 1.0f * ELLIE_WALK_SPEED * _DeltaTime, 0.0f, 0.0f });
		break;

	case EllieState::EllieWALK_Vector::WALK_RIGHT_UP:
		ELLIE->ChangeAnimation("ELLIE_WALK_RIGHT_UP");
		ELLIE_HAT->ChangeAnimation("HAT_WALK_RIGHT_UP");
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