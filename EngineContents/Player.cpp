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
		ELLIE->CreateAnimation("ELLIE_IDLE_UP", "Ellie_Basic_Idle.png", 19, 22, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_DOWN", "Ellie_Basic_Idle.png", 7, 10, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_LEFT", "Ellie_Basic_Idle.png", 3, 6, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_LEFT_UP", "Ellie_Basic_Idle.png", 15, 18, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_RIGHT", "Ellie_Basic_Idle.png", 11, 14, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_RIGHT_UP", "Ellie_Basic_Idle.png", 23, 26, ELLIE_ANIMDEFAULT_SPEED);
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

	ELLIE->ChangeAnimation("ELLIE_IDLE_DOWN");
	ELLIE->SetAutoScale(true);
	ELLIE->SetRelativeLocation({ 0, 0, 0 });
	ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT");
	ELLIE_HAT->SetAutoScale(true);
	ELLIE_HAT->SetRelativeLocation({ 0, 0, -1 });

	ELLIE_COL = CreateDefaultSubObject<UCollision>();
	ELLIE_COL->SetCollisionProfileName("Player");
	ELLIE_COL->SetWorldLocation({ 0, 70, 0 });
	ELLIE_COL->SetScale3D({10, 10, 1});
	
	//ELLIE_SHADOW->SetupAttachment(RootComponent);
	ELLIE_COL->SetupAttachment(RootComponent);
	ELLIE->SetupAttachment(RootComponent);
	ELLIE_HAT->SetupAttachment(RootComponent);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(this->GetActorLocation());
	Camera->GetCameraComponent()->SetFar(10000);
	Camera->GetCameraComponent()->SetNear(-100);
	//Camera->GetCameraComponent()->SetZSort(0, false);
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

	switch (CurState)
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

	CurState = _CurPlayerState;
}

void APlayer::SetEllieAnimation(const std::string_view& _EllieAnimation, const std::string_view& _HatAnimation/* = ""*/)
{
	ELLIE->ChangeAnimation(_EllieAnimation);
	if (!_HatAnimation.empty())
	{
		ELLIE_HAT->SetActive(true);
		ELLIE_HAT->ChangeAnimation(_HatAnimation);
	}
	else
	{
		ELLIE_HAT->SetActive(false);
	}
}

void APlayer::EllieMove(float _DeltaTime)
{
	SwitchCurState_Speed();
	FVector NEXTPOS = CurVector * CurState_Speed * _DeltaTime;
	std::vector<UCollision*> Result;
	if (false != ELLIE_COL->CollisionCheck("Field", NEXTPOS, Result))
	{
		Camera->AddActorLocation(NEXTPOS);
		AddActorLocation(NEXTPOS);
	}
}

void APlayer::EllieIDLE(float _DeltaTime)
{
	if (UEngineInput::IsPress('A') ||
		UEngineInput::IsPress('D') ||
		UEngineInput::IsPress('W') ||
		UEngineInput::IsPress('S'))
	{
		ChangeState(EllieState::State::WALK);
		return;
	}

	if (UEngineInput::IsPress('A') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('D') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('W') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('S') && UEngineInput::IsPress(VK_LSHIFT))
	{
		ChangeState(EllieState::State::RUN);
		return;
	}

	switch (CurPosVector)
	{
	case EllieState::POSVECTOR::UP:
		SetEllieAnimation("ELLIE_IDLE_UP", "HAT_IDLE_BACK");
		break;

	case EllieState::POSVECTOR::DOWN:
		SetEllieAnimation("ELLIE_IDLE_DOWN", "HAT_IDLE_FRONT");
		break;

	case EllieState::POSVECTOR::LEFT:
		SetEllieAnimation("ELLIE_IDLE_LEFT", "HAT_IDLE_FRONT_LEFT");
		break;

	case EllieState::POSVECTOR::LEFT_UP:
		SetEllieAnimation("ELLIE_IDLE_LEFT_UP", "HAT_IDLE_BACK_LEFT");
		break;

	case EllieState::POSVECTOR::LEFT_DOWN:
		SetEllieAnimation("ELLIE_IDLE_LEFT", "HAT_IDLE_FRONT_LEFT");
		break;

	case EllieState::POSVECTOR::RIGHT:
		SetEllieAnimation("ELLIE_IDLE_RIGHT", "HAT_IDLE_FRONT_RIGHT");
		break;

	case EllieState::POSVECTOR::RIGHT_UP:
		SetEllieAnimation("ELLIE_IDLE_RIGHT_UP", "HAT_IDLE_BACK_RIGHT");
		break;

	case EllieState::POSVECTOR::RIGHT_DOWN:
		SetEllieAnimation("ELLIE_IDLE_RIGHT", "ELLIE_IDLE_RIGHT");
		break;

	default:
		SetEllieAnimation("ELLIE_IDLE_DOWN", "HAT_IDLE_FRONT");
		break;
	}
}

void APlayer::EllieWALK(float _DeltaTime)
{
	if (UEngineInput::IsUp('A') ||
		UEngineInput::IsUp('D') ||
		UEngineInput::IsUp('W') ||
		UEngineInput::IsUp('S'))
	{
		ChangeState(EllieState::State::IDLE);
		return;
	}

	if (UEngineInput::IsPress('A') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('D') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('W') && UEngineInput::IsPress(VK_LSHIFT) ||
		UEngineInput::IsPress('S') && UEngineInput::IsPress(VK_LSHIFT)) 
	{
		ChangeState(EllieState::State::RUN);
		return;
	}

	if (UEngineInput::IsPress('W'))
	{
		CurVector = VECTOR_UP;
		CurPosVector = EllieState::POSVECTOR::UP;
	}
	if (UEngineInput::IsPress('S'))
	{
		CurVector = VECTOR_DOWN;
		CurPosVector = EllieState::POSVECTOR::DOWN;
	}
	if (UEngineInput::IsPress('A'))
	{
		CurVector = VECTOR_LEFT;
		CurPosVector = EllieState::POSVECTOR::LEFT;
	}
	if (UEngineInput::IsPress('D'))
	{
		CurVector = VECTOR_RIGHT;
		CurPosVector = EllieState::POSVECTOR::RIGHT;
	}

	switch (CurPosVector)
	{
	case EllieState::POSVECTOR::UP:
		SetEllieAnimation("ELLIE_WALK_UP", "HAT_WALK_UP");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::DOWN:
		SetEllieAnimation("ELLIE_WALK_DOWN", "HAT_WALK_DOWN");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::LEFT:
		SetEllieAnimation("ELLIE_WALK_LEFT", "HAT_WALK_LEFT");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::LEFT_UP:
		SetEllieAnimation("ELLIE_WALK_LEFT_UP", "HAT_WALK_LEFT_UP");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::RIGHT:
		SetEllieAnimation("ELLIE_WALK_RIGHT", "HAT_WALK_RIGHT");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::RIGHT_UP:
		SetEllieAnimation("ELLIE_WALK_RIGHT_UP", "HAT_WALK_RIGHT_UP");
		EllieMove(_DeltaTime);
		break;
	}
}

void APlayer::EllieRUN(float _DeltaTime)
{
	if (UEngineInput::IsUp('A') ||
		UEngineInput::IsUp('D') ||
		UEngineInput::IsUp('W') ||
		UEngineInput::IsUp('S'))
	{
		ChangeState(EllieState::State::IDLE);
		return;
	}

	if (UEngineInput::IsPress('A') && UEngineInput::IsUp(VK_LSHIFT) ||
		UEngineInput::IsPress('D') && UEngineInput::IsUp(VK_LSHIFT) ||
		UEngineInput::IsPress('W') && UEngineInput::IsUp(VK_LSHIFT) ||
		UEngineInput::IsPress('S') && UEngineInput::IsUp(VK_LSHIFT))
	{
		ChangeState(EllieState::State::WALK);
		return;
	}

	if (UEngineInput::IsPress('W') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_UP;
		CurPosVector = EllieState::POSVECTOR::UP;
	}
	if (UEngineInput::IsPress('S') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_DOWN;
		CurPosVector = EllieState::POSVECTOR::DOWN;
	}
	if (UEngineInput::IsPress('A') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_LEFT;
		CurPosVector = EllieState::POSVECTOR::LEFT;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_RIGHT;
		CurPosVector = EllieState::POSVECTOR::RIGHT;
	}

	switch (CurPosVector)
	{
	case EllieState::POSVECTOR::UP:
		SetEllieAnimation("ELLIE_RUN_UP", "HAT_RUN_UP");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::DOWN:
		SetEllieAnimation("ELLIE_RUN_DOWN", "HAT_RUN_DOWN");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::LEFT:
		SetEllieAnimation("ELLIE_RUN_LEFT", "HAT_RUN_LEFT");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::LEFT_UP:
		SetEllieAnimation("ELLIE_RUN_LEFT_UP", "HAT_RUN_LEFT_UP");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::RIGHT:
		SetEllieAnimation("ELLIE_RUN_RIGHT", "HAT_RUN_RIGHT");
		EllieMove(_DeltaTime);
		break;

	case EllieState::POSVECTOR::RIGHT_UP:
		SetEllieAnimation("ELLIE_RUN_RIGHT_UP", "HAT_RUN_RIGHT_UP");
		EllieMove(_DeltaTime);
		break;
	}
}

