#pragma once
#include <EngineBase/Object.h>

// ���ϱ����� �̾߱��� ���ô�.
// ���� :
// �𸮾󿡼� Actor�� ���� Ʈ�������� ������ �ʴ´�.
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
