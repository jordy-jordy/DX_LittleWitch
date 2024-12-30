#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/Level.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineSprite.h>

#include "TitleGameMode.h"
#include "PlayGameMode.h"
#include "EndGameMode.h"


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
	DirLoad();
	SpritesInit();

	UEngineCore::CreateLevel<ATitleGameMode, APawn>("TITLE");
	UEngineCore::CreateLevel<APlayGameMode, APawn>("PLAY");
	UEngineCore::CreateLevel<AEndGameMode, APawn>("END");

	UEngineCore::OpenLevel("TITLE");
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

void UContentsCore::DirLoad()
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}
	Dir.Append("Image//WitchResource");
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}
}

void UContentsCore::SpritesInit()
{
	UEngineSprite::CreateSpriteToMeta("Logo.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Logo.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge_Down.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge_Shadow.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Cloud_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Cloud_1.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Cloud_2.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Cloud_3.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_CloudBlur_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_CloudBlur_1.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Cover.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Light.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Light_Blur.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Moon.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Mountain.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_MountainWater_blur.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Sky.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_train_star.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Train_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Train_1.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Train_2.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Train_3.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Train_4.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_TrainWater_blur.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Tree_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Tree_1.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Water.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_WaterShine.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_WaterShine_blur.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Window_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Window_1.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Window_2.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_WindowWater_blur.png", ".sdata");


}
