#include "PreCompile.h"
#include "Tree.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/Collision.h>


ATree::ATree()
{
	TreeTypeValue = ETreeType::Tree0;
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Renderer->SetScale3D({ 100.0f, 100.0f });
	Renderer->SetWorldLocation({0, 0, -100});

	Collision = CreateDefaultSubObject<UCollision>();
	Collision->SetCollisionProfileName("Tree");
	Collision->SetScale3D({ 50.0f, 50.0f });

	Collision->SetupAttachment(RootComponent);
	Renderer->SetupAttachment(RootComponent);
};

ATree::~ATree()
{

};

void ATree::BeginPlay()
{
	AActor::BeginPlay();
}

void ATree::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetCamera(0);

	UEngineCore::GetMainWindow().GetMousePos();
}

void ATree::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void ATree::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}