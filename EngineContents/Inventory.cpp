#include "PreCompile.h"
#include "Inventory.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>


AInventory::AInventory() 
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Inventory = CreateDefaultSubObject<USpriteRenderer>();

	Inventory->SetupAttachment(RootComponent);
}

AInventory::~AInventory() 
{
}

void AInventory::BeginPlay()
{
	AActor::BeginPlay();

	Inventory->SetTexture("")
}

void AInventory::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}
