#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>

#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>

#include "Player.h"
#include "Field_Home.h"
#include "Field_Green.h"


class EditValue : public UEngineGUIWindow
{
public:
	void OnGUI() override
	{
		ImGui::Button("AddSpeed_Walk");
		ImGui::Button("AddSpeed_Run");
		//ImGui::SameLine(); // 한간 띄기
		ImGui::Button("SubSpeed_Walk");
		ImGui::Button("SubSpeed_Run");
		//ImGui::Text("test");
	}
};

APlayGameMode::APlayGameMode()
{
	PlayDirLoad();
	PlaySpritesInit();

	GetWorld()->CreateCollisionProfile("Player");

	GetWorld()->CreateCollisionProfile("Field");

	GetWorld()->LinkCollisionProfile("Player", "Field");
	GetWorld()->LinkCollisionProfile("Player", "Tree");

	Field_HOME = GetWorld()->SpawnActor<AField_Home>();
	Field_HOME->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	Field_HOME->SetColImage("pixel_coll.png", "02_Field");

	Player = GetWorld()->SpawnActor<APlayer>();
	Player->SetActorLocation({ 0.0f, 0.0f, 0.0f });
	Player->SetField(Field_HOME);

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->GetCameraComponent()->SetFar(10000.0f);
	Camera->GetCameraComponent()->SetNear(-100.0f);
	Camera->GetCameraComponent()->SetZSort(0, false);
};

APlayGameMode::~APlayGameMode()
{

};

void APlayGameMode::BeginPlay()
{
	AActor::BeginPlay();
}

void APlayGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_SPACE))
	{
		UEngineCore::OpenLevel("TITLE");
	}

}

void APlayGameMode::PlayDirLoad()
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	Dir.Append("Image//WitchResource//PLAY");
	std::vector<UEngineFile> ImageFiles = Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < ImageFiles.size(); i++)
	{
		std::string FilePath = ImageFiles[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}
}

void APlayGameMode::PlaySpritesInit()
{
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Idle.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Walk.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Ellie_Basic_Run.png", ".sdata");
}

