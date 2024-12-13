#pragma once
#include <EngineBase/EngineMath.h>

struct UEngineInitData
{
public:
	FVector WindowSize;
};


// 설명 : 대부분의 프로그래밍 언어에서
//       인터페이스는 오로지 함수를 뭘 구현해야하는지에 대한 지침을 내려주는 정도의 내용으로 짜여져 있다.
class IContentsCore
{
public:
	virtual ~IContentsCore() = 0 {};

	virtual void EngineStart(UEngineInitData& _Data) = 0 {};
	virtual void EngineTick(float _DeltaTime) {};
	virtual void EngineEnd() {};
};

