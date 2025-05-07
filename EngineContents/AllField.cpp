#include "PreCompile.h"
#include "AllField.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>


AAllField::AAllField()
{

};

AAllField::~AAllField()
{

};

void AAllField::SetColImage(std::string_view _ColImageName, std::string_view _FolderName)
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
