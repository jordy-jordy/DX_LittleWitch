#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineRenderTarget.h>

#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>

#include "Player.h"
#include "Field_Green.h"
#include "Field_Home.h"


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
	GetWorld()->CreateCollisionProfile("Tree");
	GetWorld()->CreateCollisionProfile("MovePoint");

	GetWorld()->LinkCollisionProfile("Player", "Field");
	GetWorld()->LinkCollisionProfile("Player", "Tree");
	GetWorld()->LinkCollisionProfile("Player", "MovePoint");
};

APlayGameMode::~APlayGameMode()
{

};

void APlayGameMode::BeginPlay()
{
	AGameMode::BeginPlay();
	UEngineCore::GetDevice().GetBackBufferTarget()->SetClearColor({ 0.337f, 0.388f, 0.263f, 1.0f });

	//Field_Green = GetWorld()->SpawnActor<AField_Green>();
	//Field_Green->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	//Field_Green->SetColImage("Field_Green_001.png", FieldFolderName);

	Field_Home = GetWorld()->SpawnActor<AField_Home>();
	Field_Home->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	Field_Home->SetColImage("Field_Home_001.png", FieldFolderName);

	SetCurField(Field_Home);
	SetFieldColImageName();

	Player = dynamic_cast<APlayer*>(GetWorld()->GetMainPawn());
	Player->SetActorLocation({ 0.0f, 200.0f, 0.0f });
	Player->SetField(CurField);
	Player->SetColImage(FieldColImageName, FieldFolderName);
}

void APlayGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_SPACE))
	{
		UEngineCore::OpenLevel("TITLE");
	}

}

void APlayGameMode::SetFieldColImageName()
{
	if (CurField == Field_Green)
	{
		Field = FieldList::GREEN;
	}
	if (CurField == Field_Home)
	{
		Field = FieldList::HOME;
	}

	switch (Field)
	{
	case FieldList::HOME:
		FieldColImageName = "Field_Home_001.png";
		break;

	case FieldList::GREEN:
		FieldColImageName = "Field_Green_001.png";
		break;

	default:
		break;
	}
}

void APlayGameMode::SetCurField(std::shared_ptr<class AAllField> _CurField)
{
	CurField = _CurField;
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

