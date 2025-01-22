#include "PreCompile.h"
#include "Field_Green.h"

#include <EnginePlatform/EngineWinImage.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

#include "AllField.h"

#include "GlobalVar.h"


AField_Green::AField_Green()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FieldImage = CreateDefaultSubObject<USpriteRenderer>();
	FieldColIamge = CreateDefaultSubObject<USpriteRenderer>();
	FieldCol = CreateDefaultSubObject<UCollision>();

	FieldImage->SetupAttachment(RootComponent);
	FieldColIamge->SetupAttachment(RootComponent);
	FieldCol->SetupAttachment(RootComponent);

};

void AField_Green::BeginPlay()
{
	AActor::BeginPlay();

	ACameraActor* Camera = GetWorld()->GetMainCamera().get();
	Camera->GetCameraComponent().get()->SetZSort(0, true);

	FieldImage->SetRelativeScale3D(FieldSize_Plus);
	FieldImage->SetWorldLocation({ 0, 0, 1000 });
	FieldImage->SetTexture("Field_Green_000.png");

	FieldColIamge->SetRelativeScale3D(FieldSize_Plus);
	FieldColIamge->SetWorldLocation({ 0, 0, 300 });
	FieldColIamge->SetTexture("Field_Green_001.png");
	FieldColIamge->SetActive(false);

	FieldCol->SetCollisionProfileName("Field");
	FieldCol->SetScale3D({ FieldSize_Plus.X - ELLIESIZE.X, FieldSize_Plus.Y - ELLIESIZE.Y });
}

void AField_Green::SetColImage(std::string_view _ColImageName, std::string_view _FolderName) 
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

void AField_Green::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_F1))
	{
		FieldColIamge->SetActiveSwitch();
	}

}

AField_Green::~AField_Green()
{

};

