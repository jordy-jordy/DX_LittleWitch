#pragma once
#include "EngineResources.h"
#include "EngineDeviceBuffer.h"
#include "EngineEnums.h"

// Ÿ�ϸ��� 2����� �մϴ�.
// 300����Ʈ¥�� 100�� ¥�� Ÿ�ϸ��� �ְ�
// 300����Ʈ¥�� 80�� ¥�� Ÿ�ϸ��� �ִ�.


// ���� :
class UEngineStructuredBuffer
{
public:
	// constrcuter destructer
	UEngineStructuredBuffer();
	~UEngineStructuredBuffer();

	// delete Function
	UEngineStructuredBuffer(const UEngineStructuredBuffer& _Other) = delete;
	UEngineStructuredBuffer(UEngineStructuredBuffer&& _Other) noexcept = delete;
	UEngineStructuredBuffer& operator=(const UEngineStructuredBuffer& _Other) = delete;
	UEngineStructuredBuffer& operator=(UEngineStructuredBuffer&& _Other) noexcept = delete;

protected:

private:
	//              ������ �ϳ��� ũ��
	//              �������� ���� Back
	// std::map<key, value, std::less> 
	/*static std::map<int, std::map<int, std::map<std::string, std::shared_ptr<UEngineConstantBuffer>>>> BufferMap;*/
};

