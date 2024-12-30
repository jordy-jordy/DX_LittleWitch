#include "PreCompile.h"
#include "Field.h"

AField::AField()
{

};

AField::~AField()
{

};

void AField::BeginPlay()
{
	AActor::BeginPlay();
}

void AField::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
