#include "PreCompile.h"
#include "Field_Home.h"

#include <EnginePlatform/EngineWinImage.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "AllField.h"

#include "GlobalVar.h"


AField_Home::AField_Home()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FieldImage = CreateDefaultSubObject<USpriteRenderer>();
	FieldImage->SetRelativeScale3D(HomeFieldSize);
	FieldImage->SetWorldLocation({0, 0, 200});
	FieldImage->SetTexture("test_field.png");

	FieldColIamge = CreateDefaultSubObject<USpriteRenderer>();
	FieldColIamge->SetRelativeScale3D({800, 800});
	FieldColIamge->SetWorldLocation({ 0, 0, 100 });
	FieldColIamge->SetTexture("pixel_coll.png");

	FieldCol = CreateDefaultSubObject<UCollision>();
	FieldCol->SetCollisionProfileName("Field");
	FieldCol->SetScale3D({ HomeFieldSize.X - ELLIESIZE.X, HomeFieldSize.Y - ELLIESIZE.Y });

	FieldImage->SetupAttachment(RootComponent);
	FieldColIamge->SetupAttachment(RootComponent);
	FieldCol->SetupAttachment(RootComponent);

	ColImageDir = "ContentsResources\\Image\\WitchResource\\PLAY";
};

void AField_Home::BeginPlay()
{
	AActor::BeginPlay();
}

void AField_Home::SetColImage(std::string_view _ColImageName, std::string_view _FolderName) 
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

void AField_Home::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

AField_Home::~AField_Home()
{

};

