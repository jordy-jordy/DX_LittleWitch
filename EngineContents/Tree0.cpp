#include "PreCompile.h"
#include "Tree0.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/Collision.h>


ATree0::ATree0()
{
	TreeTypeValue = ETreeType::Tree0;
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Renderer_Tree_000 = CreateDefaultSubObject<USpriteRenderer>();
	Renderer_Tree_000->SetSprite("Trees", 0);
	Renderer_Tree_000->SetScale3D({ 100.0f, 100.0f });
	Renderer_Tree_000->SetWorldLocation({0, 0, -100});

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetCollisionProfileName("Tree");
	Collision->SetScale3D({ 50.0f, 50.0f });

	Collision->SetupAttachment(RootComponent);
	Renderer_Tree_000->SetupAttachment(RootComponent);
};

ATree0::~ATree0()
{

};

void ATree0::BeginPlay()
{
	AActor::BeginPlay();
}

void ATree0::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);

	UEngineCore::GetMainWindow().GetMousePos();
}

void ATree0::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void ATree0::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}