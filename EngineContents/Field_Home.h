#pragma once
#include "AllField.h"
#include "GlobalVar.h"


// Ό³Έν :
class AField_Home : public AAllField
{
public:
	// constrcuter destructer
	AField_Home();
	~AField_Home();

	// delete Function
	AField_Home(const AField_Home& _Other) = delete;
	AField_Home(AField_Home&& _Other) noexcept = delete;
	AField_Home& operator=(const AField_Home& _Other) = delete;
	AField_Home& operator=(AField_Home&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer>GetHomeFieldColImage();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};
