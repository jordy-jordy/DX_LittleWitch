#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>

#include "GlobalVar.h"
#include "TitleGameMode.h"
#include "PlayGameMode.h"
#include "EndGameMode.h"
#include "Player.h"


CreateContentsCoreDefine(UContentsCore);

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::EngineStart(UEngineInitData& _Data)
{
	WidowSizePos(_Data);

	UEngineCore::CreateLevel<ATitleGameMode, APawn>("TITLE");
	UEngineCore::CreateLevel<APlayGameMode, APlayer>("PLAY");
	//UEngineCore::CreateLevel<AEndGameMode, APawn>("END");

	UEngineCore::OpenLevel(START_MODE);
}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}

void UContentsCore::WidowSizePos(UEngineInitData& _Data)
{
	// ���ϴ� �������� Ŭ���̾�Ʈ ũ�� ����
	_Data.WindowSize = WINDOW_SIZE;

	// ����� �ػ󵵸� ������
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Ŭ���̾�Ʈ ũ�⸦ ������� ���� ������ ũ�⸦ ���
	RECT windowRect = { 0, 0, _Data.WindowSize.iX(), _Data.WindowSize.iY() };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// ��ü ������ ũ�� ���
	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	// ȭ�� �߾ӿ� ��ġ�ϵ��� ���
	_Data.WindowPos = {
		(screenWidth - windowWidth) / 2,  // X ��ǥ
		(screenHeight - windowHeight) / 2 // Y ��ǥ
	};
}

