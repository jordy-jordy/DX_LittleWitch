#include "PreCompile.h"
#include "Slot.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>


ASlot::ASlot()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Slot_Unlock = CreateDefaultSubObject<USpriteRenderer>().get();
	Slot_Lock = CreateDefaultSubObject<USpriteRenderer>().get();

	Slot_Unlock->SetupAttachment(RootComponent);
	Slot_Lock->SetupAttachment(RootComponent);

};

ASlot::~ASlot()
{

};