#pragma once
#include <EngineCore/Actor.h>


enum class PlayerIDLE_Vector
{
	NONE = 0,
	IDLE_FRONT_LEFT = 1,
	IDLE_FRONT = 2,
	IDLE_FRONT_RIGHT = 3,
	IDLE_BACK_LEFT = 4,
	IDLE_BACK = 5,
	IDLE_BACK_RIGHT = 6
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

