#pragma once
#include <EngineBase/Object.h>

// C
// #include <memory.h>
// C++
#include <memory>

// 설명 :
class UActorComponent : public UObject
{
	friend class AActor;

public:
	// constrcuter destructer
	UActorComponent();
	~UActorComponent();

	// delete Function
	UActorComponent(const UActorComponent& _Other) = delete;
	UActorComponent(UActorComponent&& _Other) noexcept = delete;
	UActorComponent& operator=(const UActorComponent& _Other) = delete;
	UActorComponent& operator=(UActorComponent&& _Other) noexcept = delete;

	template<typename ConvertType>
	ConvertType* GetActor()
	{
		return dynamic_cast<ConvertType*>(GetActor());
	}

	ENGINEAPI class AActor* GetActor();
	ENGINEAPI virtual void InitializeComponent() {}
	ENGINEAPI virtual void BeginPlay() {}
	ENGINEAPI virtual void ComponentTick(float _DeltaTime) {};

	class ULevel* GetWorld();

	ENGINEAPI bool IsActive() override;

	ENGINEAPI bool IsDestroy() override;

protected:

private:

	// 액터에 들어갈수 있다. 개념
	// std::shared_ptr<class AActor> 
	// std::weak_ptr
	class AActor* Actor;
};

