#include "PreCompile.h"
#include "Inventory.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>


AInventory::AInventory() 
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Inventory = CreateDefaultSubObject<USpriteRenderer>().get();

	Inventory->SetupAttachment(RootComponent);
}

AInventory::~AInventory() 
{
}

void AInventory::BeginPlay()
{
	AActor::BeginPlay();
	Inventory->SetTexture("Inventory_Base_mod.png");

}

void AInventory::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}
