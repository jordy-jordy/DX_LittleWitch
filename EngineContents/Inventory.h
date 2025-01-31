#pragma once
#include <EngineCore/Actor.h>
#include "Slot.h"
#include "Item.h"


// Ό³Έν :
class AInventory : public AActor
{
public:
    // constrcuter destructer
    AInventory();
    ~AInventory();

    // delete Function
    AInventory(const AInventory& _Other) = delete;
    AInventory(AInventory&& _Other) noexcept = delete;
    AInventory& operator=(const AInventory& _Other) = delete;
    AInventory& operator=(AInventory&& _Other) noexcept = delete;

protected:
    void BeginPlay() override;
    void Tick(float _DeltaTime) override;


private:
    class USpriteRenderer* Inventory;


};