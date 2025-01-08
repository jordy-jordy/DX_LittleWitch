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
	// 원하는 윈도우의 클라이언트 크기 설정
	_Data.WindowSize = WINDOW_SIZE;

	// 모니터 해상도를 가져옴
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// 클라이언트 크기를 기반으로 실제 윈도우 크기를 계산
	RECT windowRect = { 0, 0, _Data.WindowSize.iX(), _Data.WindowSize.iY() };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// 전체 윈도우 크기 계산
	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	// 화면 중앙에 위치하도록 계산
	_Data.WindowPos = {
		(screenWidth - windowWidth) / 2,  // X 좌표
		(screenHeight - windowHeight) / 2 // Y 좌표
	};
}

