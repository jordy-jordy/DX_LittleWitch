#include "PreCompile.h"
#include "TitleGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>

#include "TitleScene.h"

class TestWindow : public UEngineGUIWindow
{
public:
	void OnGUI() override
	{
		ImGui::Button("WindowButton");
		ImGui::SameLine(); // 한간 띄기
		ImGui::Text("test");

	}
};

ATitleGameMode::ATitleGameMode()
{
	TitleDirLoad();
	TitleSpritesInit();

	Title = GetWorld()->SpawnActor<ATitleScene>();
	//Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
	//Logo->GetRenderer()->SetSpriteData(4);

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	std::shared_ptr<UEngineCamera> CameraComp = Camera->GetCameraComponent();
	CameraComp->SetFar(10000.0f);
	

	//UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	AActor::BeginPlay();
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress(VK_SPACE))
	{
		UEngineCore::OpenLevel("PLAY");
	}

}

void ATitleGameMode::TitleDirLoad()
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	Dir.Append("Image//WitchResource//TITLE");
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}
}

void ATitleGameMode::TitleSpritesInit()
{
	UEngineSprite::CreateSpriteToMeta("Logo.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Logo.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge_Down.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Title_Train_Bridge_Shadow.png", ".sdata");
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
	UEngineSprite::CreateSpriteToMeta("CLOUD_FAR.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("CLOUD_NEAR.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("CLOUD_MIDDLE.png", ".sdata");


}
