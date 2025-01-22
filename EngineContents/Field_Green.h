#pragma once
#include "AllField.h"

#include "GlobalVar.h"


// Ό³Έν :
class AField_Green : public AAllField
{
public:
	// constrcuter destructer
	AField_Green();
	~AField_Green();

	// delete Function
	AField_Green(const AField_Green& _Other) = delete;
	AField_Green(AField_Green&& _Other) noexcept = delete;
	AField_Green& operator=(const AField_Green& _Other) = delete;
	AField_Green& operator=(AField_Green&& _Other) noexcept = delete;

	void SetColImage(std::string_view _ColImageName, std::string_view _FolderName) override;

	UEngineWinImage& GetColImage() override
	{
		return ColImage;
	}

	FVector GetFieldSize_Plus() override
	{
		return FieldSize_Plus;
	}

	std::shared_ptr<class UCollision> Col_ToHome;
	std::shared_ptr<class UCollision> Col_ToNPC;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	UEngineWinImage ColImage;

	FVector FieldSize = { 720.0f , 604.0f , 0.0f };
	FVector FieldSize_Plus = FieldSize * ScaleRatio;

};
