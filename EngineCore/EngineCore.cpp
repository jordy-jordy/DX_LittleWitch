#include "PreCompile.h"
#include "EngineCore.h"
#include <EngineBase/EngineDebug.h>
#include <EnginePlatform/EngineWindow.h>
#include "IContentsCore.h"

UEngineWindow UEngineCore::MainWindow;
HMODULE UEngineCore::ContentsDLL = nullptr;

UEngineCore::UEngineCore()
{
}

UEngineCore::~UEngineCore()
{
}

void UEngineCore::WindowInit(HINSTANCE _Instance)
{
	UEngineWindow::EngineWindowInit(_Instance);
	MainWindow.Open("MainWindow");
}

void UEngineCore::LoadContents(std::string_view _DllName)
{
	UEngineDirectory Dir;


	Dir.MoveParentToDirectory("Build");
	Dir.Move("bin/x64");

	// 빌드 상황에 따라서 경로 변경
#ifdef _DEBUG
	Dir.Move("Debug");
#else
	Dir.Move("Release");
#endif

	Dir.GetFile(_DllName);



	// 규칙이 생길수밖에 없다.
	ContentsDLL = LoadLibraryA("D:/Project/GM2/CPPTest/DLLTest/Build/Bin/x64/Debug/EngineContents.dll");

	if (nullptr == ContentsDLL)
	{
		MSGASSERT("컨텐츠 기능을 로드할수가 없습니다.");
		return;
	}
}

void UEngineCore::EngineStart(HINSTANCE _Instance, std::string_view _DllName)
{
	UEngineDebug::LeakCheck();

	WindowInit(_Instance);

	LoadContents(_DllName);

	UEngineInitData Data;




	// 윈도우와는 무관합니다.
	UEngineWindow::WindowMessageLoop(
		[]()
		{

			// 시작할때 하고 싶은것
			// 1. 윈도우창 크기 바꾸고 싶다.
			//    문제 : 컨텐츠만이 할수 있다.
		},
		[]()
		{
			// 엔진이 돌아갈때 하고 싶은것
		},
		[]()
		{
			// 엔진이 끝났을때 하고 싶은것.
		});


	// 게임 엔진이 시작되었다.
	// 윈도우창은 엔진이 알아서 띄워줘야 하고.

	// Window 띄워줘야 한다.

	
}