#pragma once
#include <EngineCore/Actor.h>

#include <EnginePlatform//EngineWinImage.h>

#include "GlobalVar.h"


// 설명 :
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

	virtual void InitializeField
	(
		std::shared_ptr<class USpriteRenderer> _Image, 
		std::shared_ptr<class USpriteRenderer> _ColImage, 
		std::shared_ptr<class UCollision> _Collision
	)
	{
		FieldImage = _Image;
		FieldColIamge = _ColImage;
		FieldCol = _Collision;
	}

	virtual void SetColImage(std::string_view _ColImageName, std::string_view _FolderName)
	{
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


protected:
	std::shared_ptr<class USpriteRenderer> FieldImage;
	std::shared_ptr<class USpriteRenderer> FieldColIamge;
	std::shared_ptr<class UCollision> FieldCol;

	UEngineWinImage ColImage;
	std::string_view ColImageDir;


private:

};
