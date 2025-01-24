#include "PreCompile.h"
#include "Field_Home.h"

#include <EnginePlatform/EngineWinImage.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

#include "AllField.h"

#include "GlobalVar.h"


AField_Home::AField_Home()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FieldImage = CreateDefaultSubObject<USpriteRenderer>();
	FieldColIamge = CreateDefaultSubObject<USpriteRenderer>();
	FieldCol = CreateDefaultSubObject<UCollision>();
	Col_ToGreen = CreateDefaultSubObject<UCollision>();

	FieldImage->SetupAttachment(RootComponent);
	FieldColIamge->SetupAttachment(RootComponent);
	FieldCol->SetupAttachment(RootComponent);
	Col_ToGreen->SetupAttachment(RootComponent);

};

void AField_Home::BeginPlay()
{
	AActor::BeginPlay();

	FieldImage->SetRelativeScale3D(FieldSize_Plus);
	FieldImage->SetWorldLocation({ 0, 0, 10000 });
	FieldImage->SetTexture("Field_Home_000.png");

	FieldColIamge->SetRelativeScale3D(FieldSize_Plus);
	FieldColIamge->SetWorldLocation({ 0, 0, 300 });
	FieldColIamge->SetTexture("Field_Home_001.png");
	FieldColIamge->SetActive(false);

	FieldCol->SetCollisionProfileName("Field");
	FieldCol->SetScale3D({ FieldSize_Plus.X - ELLIESIZE.X, FieldSize_Plus.Y - ELLIESIZE.Y });

	Col_ToGreen->SetCollisionProfileName("Point_ToGreen");
	Col_ToGreen->SetScale3D({ 144.0f * ScaleRatio, 32.0f * ScaleRatio });
	Col_ToGreen->SetRelativeLocation({ -(FieldSize.Half().X - 264.0f) * ScaleRatio, (FieldSize.Half().Y - 448.0f) * ScaleRatio });

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

	if (UEngineInput::IsDown(VK_F1))
	{
		FieldColIamge->SetActiveSwitch();
	}

}

AField_Home::~AField_Home()
{

};

