#pragma once
#include <EngineCore/Actor.h>

#include "GlobalVar.h"


struct EllieState
{
	enum class State
	{
		NONE = 0,
		IDLE = 1,
		WALK = 2,
		RUN = 3,
		MAX
	};

	enum class POSVECTOR
	{
		NONE = 0,
		UP = 1,
		DOWN = 2,
		LEFT = 3,
		LEFT_UP = 4,
		LEFT_DOWN = 5,
		RIGHT = 6,
		RIGHT_UP = 7,
		RIGHT_DOWN = 8,
		MAX
	};
};

// Ό³Έν :
class APlayer : public APawn
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void EllieIDLE(float _DeltaTime);
	void EllieWALK(float _DeltaTime);
	void EllieRUN(float _DeltaTime);

	void EllieMove(float _DeltaTime);
	void SwitchCurState_Speed()
	{
		if (CurState == EllieState::State::WALK)
		{
			CurState_Speed = ELLIE_WALK_SPEED;
		}

		if (CurState == EllieState::State::RUN)
		{
			CurState_Speed = ELLIE_RUN_SPEED;
		}
	}

	void ChangeState(EllieState::State _CurPlayerState);
	void SetEllieAnimation(const std::string_view& _EllieAnimation, const std::string_view& _HatAnimation = "");


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	float CurState_Speed = 0.0f;

	FVector CurVector = VECTOR_NONE;
	EllieState::State CurState = EllieState::State::IDLE;
	EllieState::POSVECTOR CurPosVector = EllieState::POSVECTOR::NONE;

	std::shared_ptr<class USpriteRenderer> ELLIE_SHADOW;
	std::shared_ptr<class USpriteRenderer> ELLIE;
	std::shared_ptr<class USpriteRenderer> ELLIE_HAT;

	std::shared_ptr<class UCollision> ELLIE_COL;
};

