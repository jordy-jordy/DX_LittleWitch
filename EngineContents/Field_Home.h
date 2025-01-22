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

	void SetColImage(std::string_view _ColImageName, std::string_view _FolderName) override;

	UEngineWinImage& GetColImage() override
	{
		return ColImage;
	}

	FVector GetFieldSize_Plus() override
	{
		return FieldSize_Plus;
	}

	std::shared_ptr<class UCollision> Col_ToGreen;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	UEngineWinImage ColImage;

	FVector FieldSize = { 480.0f , 464.0f , 0.0f };
	FVector FieldSize_Plus = FieldSize * ScaleRatio;

};
