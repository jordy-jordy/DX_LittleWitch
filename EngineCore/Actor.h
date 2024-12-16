#pragma once
#include <EngineBase/Object.h>

// 기하구조를 이야기해 봅시다.
// 설명 :
// 언리얼에서 Actor는 절대 트랜스폼을 가지지 않는다.
class AActor : public UObject
{
public:
	// constrcuter destructer
	AActor();
	~AActor();

	// delete Function
	AActor(const AActor& _Other) = delete;
	AActor(AActor&& _Other) noexcept = delete;
	AActor& operator=(const AActor& _Other) = delete;
	AActor& operator=(AActor&& _Other) noexcept = delete;

protected:

private:
	// Component RootComponent

};

