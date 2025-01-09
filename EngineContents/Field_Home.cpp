#include "PreCompile.h"
#include "Field_Home.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "GlobalVar.h"


AField_Home::AField_Home()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	HomeField = CreateDefaultSubObject<USpriteRenderer>();
	HomeField->SetRelativeScale3D(HomeFieldSize);
	HomeField->SetTexture("test_field.png");

	HomeField_ColImage = CreateDefaultSubObject<USpriteRenderer>();
	HomeField_ColImage->SetRelativeScale3D({800, 800});
	HomeField_ColImage->SetTexture("pixel_coll.png");

	HomeField_Coll = CreateDefaultSubObject<UCollision>();
	HomeField_Coll->SetCollisionProfileName("Field");
	HomeField_Coll->SetScale3D({ HomeFieldSize.X - ELLIESIZE.X, HomeFieldSize.Y - ELLIESIZE.Y });

	HomeField_Coll->SetupAttachment(RootComponent);
	HomeField->SetupAttachment(RootComponent);
	HomeField_ColImage->SetupAttachment(RootComponent);
};

AField_Home::~AField_Home()
{

};

void AField_Home::BeginPlay()
{
	AActor::BeginPlay();
}

void AField_Home::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
