#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>

#include "Player.h"
#include "Field_Home.h"
#include "Field_Green.h"

APlayGameMode::APlayGameMode()
{
	PlayDirLoad();
	PlaySpritesInit();

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetFar(10000.0f);
	Camera->GetCameraComponent()->SetZSort(0, false);

	GetWorld()->CreateCollisionProfile("Field");
	GetWorld()->CreateCollisionProfile("Player");

	GetWorld()->LinkCollisionProfile("Player", "Field");

	MainField = GetWorld()->SpawnActor<AField_Home>();
	MainField->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	Player = GetWorld()->SpawnActor<APlayer>();
	Player->SetActorLocation({ 0.0f, 0.0f, 0.0f });

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
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Run.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Aurea_Idle.png", ".sdata");
}

