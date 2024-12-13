#pragma once
#include <EngineBase/EngineMath.h>

struct UEngineInitData
{
public:
	FVector WindowSize;
};


// ���� : ��κ��� ���α׷��� ����
//       �������̽��� ������ �Լ��� �� �����ؾ��ϴ����� ���� ��ħ�� �����ִ� ������ �������� ¥���� �ִ�.
class IContentsCore
{
public:
	virtual ~IContentsCore() = 0 {};

	virtual void EngineStart(UEngineInitData& _Data) = 0 {};
	virtual void EngineTick(float _DeltaTime) {};
	virtual void EngineEnd() {};
};

