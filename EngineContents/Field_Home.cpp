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

	MainField = CreateDefaultSubObject<USpriteRenderer>();
	MainField->SetRelativeScale3D(MainFieldSize);

	MainField_Coll = CreateDefaultSubObject<UCollision>();
	MainField_Coll->SetCollisionProfileName("Field");
	MainField_Coll->SetScale3D(MainField->GetWorldScale3D());

	MainField_Coll->SetupAttachment(RootComponent);
	MainField->SetupAttachment(RootComponent);
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
