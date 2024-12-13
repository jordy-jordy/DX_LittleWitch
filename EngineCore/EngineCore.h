#pragma once
#include <EngineBase/EngineDefine.h>
#include <EnginePlatform/EngineWindow.h>


// Ό³Έν :
class UEngineCore
{
public:
	// constrcuter destructer
	ENGINEAPI UEngineCore();
	ENGINEAPI virtual ~UEngineCore() = 0;

	ENGINEAPI static void EngineStart(HINSTANCE _Instance, std::string_view _DllName);

protected:

private:
	static UEngineWindow MainWindow;
	static HMODULE ContentsDLL;

	static void WindowInit(HINSTANCE _Instance);

	static void LoadContents(std::string_view _DllName);
};

