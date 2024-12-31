#include "PreCompile.h"
#include "PlayGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

#include "Player.h"

APlayGameMode::APlayGameMode()
{
	PlayDirLoad();
	PlaySpritesInit();

	Player = GetWorld()->SpawnActor<APlayer>();
};

APlayGameMode::~APlayGameMode()
{

};

void APlayGameMode::BeginPlay()
{
	AActor::BeginPlay();
}

void APlayGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}

void APlayGameMode::PlayDirLoad()
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	Dir.Append("Image//WitchResource//PLAY//00_Character");
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}
}

void APlayGameMode::PlaySpritesInit()
{
	UEngineSprite::CreateSpriteToMeta("Ellie_Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Aurea_Idle.png", ".sdata");
}

