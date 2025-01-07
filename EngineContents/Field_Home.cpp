#include "PreCompile.h"
#include "Field_Home.h"

#include "GlobalVar.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

AField_Home::AField_Home()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	MainField = CreateDefaultSubObject<USpriteRenderer>();
	MainField->SetRelativeScale3D(MainFieldSize);
	MainField->SetWorldLocation({0.0f, 0.0f, 2000.0f });

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
