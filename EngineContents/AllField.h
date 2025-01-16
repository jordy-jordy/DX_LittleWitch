#pragma once
#include <EngineCore/Actor.h>

#include <EnginePlatform//EngineWinImage.h>

#include "GlobalVar.h"


// Ό³Έν :
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

	std::string_view GetColImageDir()
	{
		return ColImageDir;
	}


protected:
	std::shared_ptr<class USpriteRenderer> FieldImage;
	std::shared_ptr<class USpriteRenderer> FieldColIamge;
	std::shared_ptr<class UCollision> FieldCol;

	UEngineWinImage ColImage;
	std::string_view ColImageDir = "ContentsResources\\Image\\WitchResource\\PLAY";


private:


};
