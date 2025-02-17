#pragma once
#include <EngineCore/Actor.h>

#include <EnginePlatform//EngineWinImage.h>

#include "GlobalVar.h"


// ���� :
class AAllField : public AActor
{
public:
	// constrcuter destructer
	AAllField();
	virtual ~AAllField();

	// delete Function
	AAllField(const AAllField& _Other) = delete;
	AAllField(AAllField&& _Other) noexcept = delete;
	AAllField& operator=(const AAllField& _Other) = delete;
	AAllField& operator=(AAllField&& _Other) noexcept = delete;

	virtual void SetColImage(std::string_view _ColImageName, std::string_view _FolderName);

	virtual UEngineWinImage& GetColImage()
	{
		return ColImage;
	}

	virtual FVector GetFieldSize()
	{
		return FieldSize;
	}

	virtual FVector GetFieldSize_Plus()
	{
		return FieldSize_Plus;
	}

	std::string_view GetColImageDir()
	{
		return ColImageDir;
	}


protected:
	class USpriteRenderer* FieldImage;
	class USpriteRenderer* FieldColIamge;
	class UCollision* FieldCol;

	UEngineWinImage ColImage;
	std::string_view ColImageDir = "ContentsResources\\Image\\WitchResource\\PLAY";

	FVector FieldSize = { 0.0f , 0.0f , 0.0f };
	FVector FieldSize_Plus = FieldSize * ScaleRatio;



private:


};
