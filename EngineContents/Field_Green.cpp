#include "PreCompile.h"
#include "Field_Green.h"

#include <EnginePlatform/EngineWinImage.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>

#include "AllField.h"

#include "GlobalVar.h"


AField_Green::AField_Green()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FieldImage = CreateDefaultSubObject<USpriteRenderer>();
	FieldImage->SetRelativeScale3D(GreenFieldSize_Plus);
	FieldImage->SetWorldLocation({0, 0, 1000});
	FieldImage->SetTexture("Field_Green_000.png");

	FieldColIamge = CreateDefaultSubObject<USpriteRenderer>();
	//FieldColIamge->SetAutoScale(true);
	//FieldColIamge->SetAutoScale(ScaleRatio);
	FieldColIamge->SetRelativeScale3D(GreenFieldSize_Plus);
	FieldColIamge->SetWorldLocation({ 0, 0, 0 });
	FieldColIamge->SetTexture("Field_Green_001.png");

	FieldCol = CreateDefaultSubObject<UCollision>();
	FieldCol->SetCollisionProfileName("Field");
	FieldCol->SetScale3D({ GreenFieldSize_Plus.X - ELLIESIZE.X, GreenFieldSize_Plus.Y - ELLIESIZE.Y });

	FieldImage->SetupAttachment(RootComponent);
	FieldColIamge->SetupAttachment(RootComponent);
	FieldCol->SetupAttachment(RootComponent);

};

void AField_Green::BeginPlay()
{
	AActor::BeginPlay();

	ACameraActor* Camera = GetWorld()->GetMainCamera().get();
	Camera->GetCameraComponent().get()->SetZSort(0, true);

}

void AField_Green::SetColImage(std::string_view _ColImageName, std::string_view _FolderName) 
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory(ColImageDir))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}

	Dir.Append(_FolderName);
	UEngineFile ImageFiles = Dir.GetFile(_ColImageName);

	ColImage.Load(nullptr, ImageFiles.GetPathToString());
}

void AField_Green::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

AField_Green::~AField_Green()
{

};

