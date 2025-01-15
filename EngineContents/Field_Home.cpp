#include "PreCompile.h"
#include "Field_Home.h"

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
};

std::shared_ptr<class USpriteRenderer>AField_Home::GetHomeFieldColImage()
{
	return FieldColIamge;
}

void AField_Home::BeginPlay()
{
	AActor::BeginPlay();
}

void AField_Home::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

AField_Home::~AField_Home()
{

};

