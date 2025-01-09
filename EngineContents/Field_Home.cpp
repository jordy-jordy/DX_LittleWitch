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

	HomeField_Coll = CreateDefaultSubObject<UCollision>();
	HomeField_Coll->SetCollisionProfileName("Field");
	HomeField_Coll->SetScale3D(HomeFieldSize * Collision_Per);

	FVector CAMERAFIELD = HomeFieldSize * Collision_Per * Camera_Per;
	std::shared_ptr<class USpriteRenderer> CameraMoveField = CreateDefaultSubObject<USpriteRenderer>();
	CameraMoveField->SetTexture("Radius_Camera.png");
	CameraMoveField->SetRelativeScale3D(CAMERAFIELD);

	HomeField_Coll->SetupAttachment(RootComponent);
	CameraMoveField->SetupAttachment(RootComponent);
	HomeField->SetupAttachment(RootComponent);
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
