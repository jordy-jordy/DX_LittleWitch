#include "PreCompile.h"
#include "Player.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/CameraActor.h>
#include <EnginePlatform/EngineWinImage.h>
#include <EnginePlatform/EngineInput.h>

#include "Field_Green.h"

#include "GlobalVar.h"


APlayer::APlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	ELLIE = CreateDefaultSubObject<USpriteRenderer>().get();
	ELLIE_HAT = CreateDefaultSubObject<USpriteRenderer>().get();
	ELLIE_SHADOW = CreateDefaultSubObject<USpriteRenderer>().get();

	/***** 엘리 - IDLE - 캐릭터 *****/
	{
		ELLIE->CreateAnimation("ELLIE_IDLE_UP", "Ellie_Basic_Idle.png", 20, 23, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_DOWN", "Ellie_Basic_Idle.png", 8, 11, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_LEFT", "Ellie_Basic_Idle.png", 4, 7, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_LEFT_UP", "Ellie_Basic_Idle.png", 16, 19, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_RIGHT", "Ellie_Basic_Idle.png", 12, 15, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_IDLE_RIGHT_UP", "Ellie_Basic_Idle.png", 24, 27, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** 엘리 - IDLE - 모자   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_LEFT", "Ellie_Basic_Idle.png", { 28, 29, 29, 30 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT", "Ellie_Basic_Idle.png", { 31, 32, 33, 34 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_FRONT_RIGHT", "Ellie_Basic_Idle.png", { 35, 36, 36, 37 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_LEFT", "Ellie_Basic_Idle.png", { 38, 39, 39, 38 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK", "Ellie_Basic_Idle.png", 0, 0, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_IDLE_BACK_RIGHT", "Ellie_Basic_Idle.png", { 40, 41, 41, 40 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** 엘리 - IDLE - 그림자 *****/
	{
		ELLIE_SHADOW->CreateAnimation("ELLIE_IDLE_SHADOW", "Ellie_Basic_Idle.png", 1, 3, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** 엘리 - WALK - 캐릭터 *****/
	{
		ELLIE->CreateAnimation("ELLIE_WALK_UP", "Ellie_Basic_Walk.png", 78, 85, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_DOWN", "Ellie_Basic_Walk.png", 42, 49, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT", "Ellie_Basic_Walk.png", 34, 41, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 66, 73, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT", "Ellie_Basic_Walk.png", 54, 61, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE->CreateAnimation("ELLIE_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 90, 98, ELLIE_ANIMDEFAULT_SPEED);
	}

	/***** 엘리 - WALK - 모자   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_WALK_UP", "Ellie_Basic_Walk.png", 0, 0, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_DOWN", "Ellie_Basic_Walk.png", { 110, 111, 0, 0, 110, 111, 0, 0 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT", "Ellie_Basic_Walk.png", { 108, 109, 100, 100, 108, 109, 100, 100 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_LEFT_UP", "Ellie_Basic_Walk.png", 0, 0, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT", "Ellie_Basic_Walk.png", { 115, 116, 117, 117, 115, 116, 117, 117 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_WALK_RIGHT_UP", "Ellie_Basic_Walk.png", 0, 0, ELLIE_ANIMDEFAULT_SPEED);
	}
	
	/***** 엘리 - WALK  - 그림자 *****/
	{
		ELLIE_SHADOW->CreateAnimation("ELLIE_WALK_SHADOW", "Ellie_Basic_Walk.png", 1, 5, ELLIE_ANIMDEFAULT_SPEED);
	}
	
	/***** 엘리 - RUN  - 캐릭터 *****/
	{
		ELLIE->CreateAnimation("ELLIE_RUN_UP", "Ellie_Basic_Run.png", 30, 35, ELLIE_ANIMDEFAULT_SPEED );
		ELLIE->CreateAnimation("ELLIE_RUN_DOWN", "Ellie_Basic_Run.png", 10, 15, ELLIE_ANIMDEFAULT_SPEED );
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT", "Ellie_Basic_Run.png", 4, 9, ELLIE_ANIMDEFAULT_SPEED );
		ELLIE->CreateAnimation("ELLIE_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 24, 25, 26, 24, 27, 28 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT", "Ellie_Basic_Run.png", 17, 22, ELLIE_ANIMDEFAULT_SPEED );
		ELLIE->CreateAnimation("ELLIE_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 37, 38, 39, 37, 40, 41 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** 엘리 - RUN  - 모자   *****/
	{
		ELLIE_HAT->CreateAnimation("HAT_RUN_UP", "Ellie_Basic_Run.png", 0, 0, ELLIE_ANIMDEFAULT_SPEED);
		ELLIE_HAT->CreateAnimation("HAT_RUN_DOWN", "Ellie_Basic_Run.png", { 47, 48, 48, 47, 49, 49 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT", "Ellie_Basic_Run.png", { 42, 43, 44, 42, 45, 46 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_LEFT_UP", "Ellie_Basic_Run.png", { 57, 58, 59, 57, 60, 61 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT", "Ellie_Basic_Run.png", { 51, 52, 53, 51, 54, 55 }, { ELLIE_ANIMDEFAULT_SPEED });
		ELLIE_HAT->CreateAnimation("HAT_RUN_RIGHT_UP", "Ellie_Basic_Run.png", { 63, 64, 65, 63, 66, 67 }, { ELLIE_ANIMDEFAULT_SPEED });
	}

	/***** 엘리 - RUN  - 그림자 *****/
	{
		ELLIE_SHADOW->CreateAnimation("ELLIE_RUN_SHADOW", "Ellie_Basic_Run.png", 1, 3, ELLIE_ANIMDEFAULT_SPEED);
	}

	
	ELLIE_SHADOW->ChangeAnimation("ELLIE_IDLE_SHADOW");
	ELLIE_SHADOW->SetAutoScale(true);
	ELLIE_SHADOW->SetAutoScaleRatio(ScaleRatio);
	ELLIE_SHADOW->SetRelativeLocation({ 0, 0, 2 });

	ELLIE->ChangeAnimation("ELLIE_IDLE_DOWN");
	ELLIE->SetAutoScale(true);
	ELLIE->SetAutoScaleRatio(ScaleRatio);
	ELLIE->SetRelativeLocation({ 0, 0, 0 });

	ELLIE_HAT->ChangeAnimation("HAT_IDLE_FRONT");
	ELLIE_HAT->SetAutoScale(true);
	ELLIE_HAT->SetAutoScaleRatio(ScaleRatio);
	ELLIE_HAT->SetRelativeLocation({ 0, 0, -2 });

	ELLIE_COL = CreateDefaultSubObject<UCollision>().get();
	ELLIE_COL->SetCollisionProfileName("Player");
	ELLIE_COL->SetWorldLocation({ 0, ELLIESIZE.Y * ScaleRatio * 0.3f, 0 });
	ELLIE_COL->SetScale3D({ 10, 10, 1 });

	ELLIE_SHADOW->SetupAttachment(RootComponent);
	ELLIE_COL->SetupAttachment(RootComponent);
	ELLIE->SetupAttachment(RootComponent);
	ELLIE_HAT->SetupAttachment(RootComponent);
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();

	Camera = GetWorld()->GetMainCamera().get();
	Camera->GetCameraComponent()->SetFar(30000.0f);
	Camera->GetCameraComponent()->SetNear(-100.0f);
	Camera->GetCameraComponent()->SetZSort(0, true);
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	{
		FVector Pos = GetActorLocation();
		Pos.Z = Pos.Y;

		SetActorLocation(Pos);
	}

	UpdateCameraLocation();

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

void APlayer::SetColImage(std::string_view _ColImageName, std::string_view _FolderName)
{
	std::string_view ColImageDir = Field->GetColImageDir();
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory(ColImageDir))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}

	Dir.Append(_FolderName);
	UEngineFile ImageFiles = Dir.GetFile(_ColImageName);

	ColImage.Load(nullptr, ImageFiles.GetPathToString());
}


void APlayer::ChangeState(EllieState::State _CurPlayerState)
{
	switch (_CurPlayerState)
	{
	case EllieState::State::IDLE:
		ELLIE_SHADOW->ChangeAnimation("ELLIE_IDLE_SHADOW");
		break;

	case EllieState::State::WALK:
		ELLIE_SHADOW->ChangeAnimation("ELLIE_WALK_SHADOW");
		break;

	case EllieState::State::RUN:
		ELLIE_SHADOW->ChangeAnimation("ELLIE_RUN_SHADOW");
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

void APlayer::UpdateCameraLocation()
{
	FVector ElliePos = this->GetActorLocation();

	FVector TargetScale = Field->GetFieldSize_Plus() * 0.5f;
	float Plus_WinSizeX = ElliePos.X + HALF_WINDOW_SIZE.X;
	float Plus_WinSizeY = ElliePos.Y + HALF_WINDOW_SIZE.Y;
	float Minus_WinSizeX = ElliePos.X - HALF_WINDOW_SIZE.X;
	float Minus_WinSizeY = ElliePos.Y - HALF_WINDOW_SIZE.Y;

	FVector NewCameraPos = ElliePos;

	if (Minus_WinSizeX < -TargetScale.X)
	{
		NewCameraPos.X = -TargetScale.X + HALF_WINDOW_SIZE.X;
	}
	else if (Plus_WinSizeX > TargetScale.X)
	{
		NewCameraPos.X = TargetScale.X - HALF_WINDOW_SIZE.X;
	}

	if (Minus_WinSizeY < -TargetScale.Y)
	{
		NewCameraPos.Y = -TargetScale.Y + HALF_WINDOW_SIZE.Y;
	}
	else if (Plus_WinSizeY > TargetScale.Y)
	{
		NewCameraPos.Y = TargetScale.Y - HALF_WINDOW_SIZE.Y;
	}

	if (TargetScale.X < HALF_WINDOW_SIZE.X)
	{
		NewCameraPos.X = 0;
	}
	if (TargetScale.Y < HALF_WINDOW_SIZE.Y)
	{
		NewCameraPos.Y = 0;
	}

	Camera->SetActorLocation(NewCameraPos);
}


void APlayer::EllieMove(float _DeltaTime)
{
	SwitchCurState_Speed();

	FVector NEXTPOS = CurVector * CurState_Speed * _DeltaTime;
	
	//FVector ColImageHALFSize = { ColImage.GetImageScale().Half().X, ColImage.GetImageScale().Half().Y };
	FVector ColImageHALFSize = { Field->GetFieldSize_Plus().Half().X, Field->GetFieldSize_Plus().Half().Y }; // *주의* ColImage는 확대 되지 않음
	FVector EllieLocation = FVector( GetActorLocation().X, (GetActorLocation().Y + ELLIESIZE_PLUS.Y * 0.3f) * -1.0f, 0.0f );
	FVector NEXTIntPOS_ColImg = ColImageHALFSize + (EllieLocation + FVector(NEXTPOS.X, NEXTPOS.Y * -1.0f, 0));
	FVector NEXTFloatPOS_ColImg = FVector{ NEXTIntPOS_ColImg.X / ScaleRatio , NEXTIntPOS_ColImg.Y / ScaleRatio }; // ColImage는 확대 되지 않기 때문에 다시 나누어 줌

	UColor Color = ColImage.GetColor(NEXTFloatPOS_ColImg);
	if (Color == UColor::BLACK)
	{
		return;
	}

	std::vector<UCollision*> Result;
	if (false != ELLIE_COL->CollisionCheck("Field", NEXTPOS, Result))
	{
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
		SetEllieAnimation("ELLIE_IDLE_RIGHT", "HAT_IDLE_FRONT_RIGHT");
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
	if (UEngineInput::IsPress('A') && UEngineInput::IsPress('W'))
	{
		CurVector = VECTOR_LEFT_UP;
		CurPosVector = EllieState::POSVECTOR::LEFT_UP;
	}
	if (UEngineInput::IsPress('A') && UEngineInput::IsPress('S'))
	{
		CurVector = VECTOR_LEFT_DOWN;
		CurPosVector = EllieState::POSVECTOR::LEFT_DOWN;
	}
	if (UEngineInput::IsPress('D'))
	{
		CurVector = VECTOR_RIGHT;
		CurPosVector = EllieState::POSVECTOR::RIGHT;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress('W'))
	{
		CurVector = VECTOR_RIGHT_UP;
		CurPosVector = EllieState::POSVECTOR::RIGHT_UP;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress('S'))
	{
		CurVector = VECTOR_RIGHT_DOWN;
		CurPosVector = EllieState::POSVECTOR::RIGHT_DOWN;
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

	case EllieState::POSVECTOR::LEFT_DOWN:
		SetEllieAnimation("ELLIE_WALK_LEFT", "HAT_WALK_LEFT");
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

	case EllieState::POSVECTOR::RIGHT_DOWN:
		SetEllieAnimation("ELLIE_WALK_RIGHT", "HAT_WALK_RIGHT");
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
	if (UEngineInput::IsPress('A') && UEngineInput::IsPress('W') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_LEFT_UP;
		CurPosVector = EllieState::POSVECTOR::LEFT_UP;
	}
	if (UEngineInput::IsPress('A') && UEngineInput::IsPress('S') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_LEFT_DOWN;
		CurPosVector = EllieState::POSVECTOR::LEFT_DOWN;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_RIGHT;
		CurPosVector = EllieState::POSVECTOR::RIGHT;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress('W') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_RIGHT_UP;
		CurPosVector = EllieState::POSVECTOR::RIGHT_UP;
	}
	if (UEngineInput::IsPress('D') && UEngineInput::IsPress('S') && UEngineInput::IsPress(VK_LSHIFT))
	{
		CurVector = VECTOR_RIGHT_DOWN;
		CurPosVector = EllieState::POSVECTOR::RIGHT_DOWN;
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

	case EllieState::POSVECTOR::LEFT_DOWN:
		SetEllieAnimation("ELLIE_RUN_LEFT", "HAT_RUN_LEFT");
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

	case EllieState::POSVECTOR::RIGHT_DOWN:
		SetEllieAnimation("ELLIE_RUN_RIGHT", "HAT_RUN_RIGHT");
		EllieMove(_DeltaTime);
		break;
	}
}

