#pragma once
#include <EngineCore/Actor.h>


enum class EllieIDLE_Vector
{
	NONE = 0,
	IDLE_FRONT_LEFT = 1,
	IDLE_FRONT = 2,
	IDLE_FRONT_RIGHT = 3,
	IDLE_BACK_LEFT = 4,
	IDLE_BACK = 5,
	IDLE_BACK_RIGHT = 6,
	MAX
};

enum class EllieWALK_Vector
{
	NONE = 0,
	WALK_UP = 1,
	WALK_DOWN = 2,
	WALK_LEFT = 3,
	WALK_LEFT_UP = 4,
	WALK_RIGHT = 5,
	WALK_RIGHT_DOWN = 6,
	MAX
};

enum class EllieRUN_Vector
{
	NONE = 0,
	RUN_UP = 1,
	RUN_DOWN = 2,
	RUN_LEFT = 3,
	RUN_LEFT_UP = 4,
	RUN_RIGHT = 5,
	RUN_RIGHT_DOWN = 6,
	MAX
};

// Ό³Έν :
class APlayer : public AActor
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



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> ELLIE;
	std::shared_ptr<class USpriteRenderer> ELLIE_HAT;
	std::shared_ptr<class USpriteRenderer> ELLIE_SHADOW;
	std::shared_ptr<class USpriteRenderer> AUREA;

};

