#include "PreCompile.h"
#include "PlayGameMode.h"

#include <EnginePlatform/EngineInput.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineRenderTarget.h>
#include <EngineCore/Collision.h>

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
	GetWorld()->CreateCollisionProfile("Point_ToHome");
	GetWorld()->CreateCollisionProfile("Point_ToGreen");
	GetWorld()->CreateCollisionProfile("Point_ToNPC");

	GetWorld()->LinkCollisionProfile("Player", "Field");
	GetWorld()->LinkCollisionProfile("Player", "Tree");
	GetWorld()->LinkCollisionProfile("Player", "Point_ToHome");
	GetWorld()->LinkCollisionProfile("Player", "Point_ToGreen");
	GetWorld()->LinkCollisionProfile("Player", "Point_ToNPC");
};

APlayGameMode::~APlayGameMode()
{

};

void APlayGameMode::BeginPlay()
{
	AGameMode::BeginPlay();
	UEngineCore::GetDevice().GetBackBufferTarget()->SetClearColor({ 0.337f, 0.388f, 0.263f, 1.0f });

	Field_Home = GetWorld()->SpawnActor<AField_Home>();
	Field_Home->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	Field_Home->SetColImage("Field_Home_001.png", FieldFolderName);
	Field_Home->SetActive(false);

	Field_Green = GetWorld()->SpawnActor<AField_Green>();
	Field_Green->SetActorLocation({ 0.0f, 0.0f, 1.0f });
	Field_Green->SetColImage("Field_Green_001.png", FieldFolderName);
	Field_Green->SetActive(false);

	SetCurField(Field_Green);

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

	ChangeField(_DeltaTime);

	switch (Field)
	{
	case FieldList::HOME:
		Field_Home->SetActive(true);
		Field_Green->SetActive(false);
		break;
	case FieldList::GREEN:
		Field_Home->SetActive(false);
		Field_Green->SetActive(true);
		break;
	}
}

void APlayGameMode::ChangeField(float _DeltaTime)
{
	std::vector<UCollision*> Result0;
	if (false != Player->GetELLIE_COL()->CollisionCheck("Point_ToHome", Result0))
	{
		SetCurField(Field_Home);
		FVector FieldHomeSize = Field_Home->GetFieldSize();
		Player->SetActorLocation({ -(FieldHomeSize.Half().X - 264.0f) * ScaleRatio, (FieldHomeSize.Half().Y - 424.0f) * ScaleRatio, 0.0f });
		Player->SetField(CurField);
		Player->SetColImage(FieldColImageName, FieldFolderName);
	}
	std::vector<UCollision*> Result1;
	if (false != Player->GetELLIE_COL()->CollisionCheck("Point_ToGreen", Result1))
	{
		SetCurField(Field_Green);
		FVector FieldGreenSize = Field_Green->GetFieldSize();
		Player->SetActorLocation({ -(FieldGreenSize.Half().X - 520.0f) * ScaleRatio, (FieldGreenSize.Half().Y - 80.0f) * ScaleRatio, 0.0f });
		Player->SetField(CurField);
		Player->SetColImage(FieldColImageName, FieldFolderName);
	}

}


void APlayGameMode::SetCurField(std::shared_ptr<class AAllField> _CurField)
{
	CurField = _CurField;

	if (_CurField == Field_Home)
	{
		Field = FieldList::HOME;
		FieldColImageName = "Field_Home_001.png";
	}
	if (_CurField == Field_Green)
	{
		Field = FieldList::GREEN;
		FieldColImageName = "Field_Green_001.png";
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

