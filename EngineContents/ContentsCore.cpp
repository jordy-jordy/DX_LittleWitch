#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>
#include "TitleGameMode.h"


CreateContentsCoreDefine(UContentsCore);

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::WidowSizePos(UEngineInitData& _Data)
{
	// ���ϴ� �������� Ŭ���̾�Ʈ ũ�� ����
	_Data.WindowSize = { 1280, 720 };

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

void UContentsCore::EngineStart(UEngineInitData& _Data)
{
	WidowSizePos(_Data);

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
			return;
		}
		Dir.Append("Image");
		std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
		for (size_t i = 0; i < ImageFiles.size(); i++)
		{
			std::string FilePath = ImageFiles[i].GetPathToString();
			UEngineTexture::Load(FilePath);
		}
	}

	UEngineSprite::CreateSpriteToMeta("Player.png", ".sdata");


	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Titlelevel");
	UEngineCore::OpenLevel("Titlelevel");
}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}