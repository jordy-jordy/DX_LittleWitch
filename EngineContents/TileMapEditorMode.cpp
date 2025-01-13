#include "PreCompile.h"
#include "TileMapEditorMode.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TileMapRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

#include "ContentsEditorGUI.h"

#include "GlobalVar.h"


enum class EEditMode
{
	TileMap,
	Object
};

class UTileMapWindow : public UEngineGUIWindow
{
public:

	int SelectItem = 0;
	int ObjectItem = -1;
	UTileMapRenderer* TileMapRenderer = nullptr;
	EEditMode Mode = EEditMode::TileMap;

	int TileCountX = 10;
	int TileCountY = 10;
	int SelectTileIndex = 0;

	void OnGUI() override
	{
		if (Mode == EEditMode::Object)
		{
			if (ImGui::Button("ObjectMode"))
			{
				Mode = EEditMode::TileMap;
			}
		}
		else
		{
			if (ImGui::Button("TileMapMode"))
			{
				Mode = EEditMode::Object;
			}
		}

		switch (Mode)
		{
		case EEditMode::TileMap:
			TileMapMode();
			break;
		case EEditMode::Object:
			break;
		default:
			break;
		}

		SaveAndLoad();
	}

	void TileMapMode()
	{
		UEngineSprite* Sprite = TileMapRenderer->GetSprite();

		for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
		{
			UEngineTexture* Texture = Sprite->GetTexture(i);
			FSpriteData Data = Sprite->GetSpriteData(i);

			//SRV�Դϴ�
			ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

			std::string Text = std::to_string(i);

			if (i != 0)
			{
				if (0 != (i % 10))
				{
					ImGui::SameLine();
				}
			}


			ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
			ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

			if (ImGui::ImageButton(Text.c_str(), SRV, { 60, 60 }, Pos, Size))
			{
				SelectTileIndex = static_cast<int>(i);
			}
			// ���͸� ġ�� �ʴ°���.
		}


		ImGui::InputInt("TileMapX", &TileCountX);
		ImGui::InputInt("TileMapY", &TileCountY);

		if (ImGui::Button("TileMap Create"))
		{
			for (int y = 0; y < TileCountY; y++)
			{
				for (int x = 0; x < TileCountX; x++)
				{
					TileMapRenderer->SetTile(x, y, SelectTileIndex);
				}
			}
		}


		if (true == UEngineInput::IsPress(VK_LBUTTON))
		{
			FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

			TileMapRenderer->SetTile(ScreenPos, SelectTileIndex);
		}

		if (true == UEngineInput::IsPress(VK_RBUTTON))
		{
			FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

			TileMapRenderer->RemoveTile(ScreenPos);
		}
	}

	void SaveAndLoad()
	{
		if (true == ImGui::Button("Save"))
		{
			UEngineDirectory Dir;
			if (false == Dir.MoveParentToDirectory("ContentsResources"))
			{
				MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
				return;
			}
			Dir.Append("Data");
			std::string InitPath = Dir.GetPathToString();

			OPENFILENAME ofn;       // common dialog box structure
			char szFile[260] = { 0 };       // if using TCHAR macros
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = nullptr;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = ("All\0*.*\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrDefExt = "MapData";
			ofn.lpstrInitialDir = InitPath.c_str();
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetSaveFileNameA(&ofn) == TRUE)
			{
				UEngineSerializer Ser;
				TileMapRenderer->Serialize(Ser);

				UEngineFile NewFile = Dir.GetFile(ofn.lpstrFile);
				NewFile.FileOpen("wb");
				NewFile.Write(Ser);
			}
		}

		if (true == ImGui::Button("Load"))
		{
			UEngineDirectory Dir;
			if (false == Dir.MoveParentToDirectory("ContentsResources"))
			{
				MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
				return;
			}
			Dir.Append("Data");
			std::string InitPath = Dir.GetPathToString();

			OPENFILENAME ofn;       // common dialog box structure
			char szFile[260] = { 0 };       // if using TCHAR macros
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = nullptr;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = ("All\0*.*\0Text\0*.MapData\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = InitPath.c_str();
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileNameA(&ofn) == TRUE)
			{
				UEngineFile NewFile = Dir.GetFile(ofn.lpstrFile);
				UEngineSerializer Ser;

				NewFile.FileOpen("rb");
				NewFile.Read(Ser);
				TileMapRenderer->DeSerialize(Ser);
			}
		}
	}
};


ATileMapEditorMode::ATileMapEditorMode()
{
	TileMapDirLoad();
	GetWorld()->CreateCollisionProfile("GUI");

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	PivotSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PivotSpriteRenderer->SetRelativeScale3D({ 10.0f, 10.0f, 1.0f });

	Renderer_Tile = CreateDefaultSubObject<UTileMapRenderer>();
	Renderer_Tile->SetTileSetting(ETileMapType::Rect, "TILEMAP_TILE", { 16.0f * ScaleRatio, 16.0f * ScaleRatio }, { 16.0f * ScaleRatio, 16.0f * ScaleRatio }, { 0.0f, 0.0f });

	PivotSpriteRenderer->SetupAttachment(RootComponent);
	Renderer_Tile->SetupAttachment(RootComponent);

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);
};


ATileMapEditorMode::~ATileMapEditorMode()
{

};


void ATileMapEditorMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ATileMapEditorMode::LevelChangeStart()
{
	UEngineGUI::AllWindowOff();

	std::shared_ptr<UContentsEditorGUI> Window = UEngineGUI::FindGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");

	if (nullptr == Window)
	{
		Window = UEngineGUI::CreateGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");
	}

	Window->SetActive(true);

	TileMapWindow = UEngineGUI::FindGUIWindow<UTileMapWindow>("TileMapWindow");

	if (nullptr == TileMapWindow)
	{
		TileMapWindow = UEngineGUI::CreateGUIWindow<UTileMapWindow>("TileMapWindow");
	}

	TileMapWindow->SetActive(true);
	TileMapWindow->TileMapRenderer = Renderer_Tile.get();
}

void ATileMapEditorMode::BeginPlay()
{
	AActor::BeginPlay();
}

void ATileMapEditorMode::TileMapDirLoad()
{

	/*16x16 Ÿ�� ���ҽ�*/
	UEngineDirectory TILEMAP_TILE_Dir;
	if (false == TILEMAP_TILE_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}
	TILEMAP_TILE_Dir.Append("Image//WitchResource//TILEMAP_TILE");
	std::vector<UEngineFile> TILES = TILEMAP_TILE_Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < TILES.size(); i++)
	{
		std::string FilePath = TILES[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}

	UEngineSprite::CreateSpriteToFolder(TILEMAP_TILE_Dir.GetPathToString());

	/*��������Ʈ Ÿ�� ���ҽ�*/
	UEngineDirectory TILEMAP_OBJECTS_Dir;
	if (false == TILEMAP_OBJECTS_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}
	TILEMAP_OBJECTS_Dir.Append("Image//WitchResource//TILEMAP_OBJECTS");
	std::vector<UEngineFile> TILES_SPRITES = TILEMAP_OBJECTS_Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < TILES_SPRITES.size(); i++)
	{
		std::string FilePath = TILES_SPRITES[i].GetPathToString();
		UEngineTexture::Load(FilePath);
	}

	UEngineSprite::CreateSpriteToMeta("grass_000.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_001.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_002.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_003.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_004.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_005.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_006.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_007.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_015.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_016.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_017.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_018.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_019.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_020.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_021.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_022.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_023.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("grass_024.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("ground_000.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("ground_002.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("ground_003.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("ground_009.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("ground_010.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_000.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_001.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_002.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_003.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_004.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_005.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("tree_006.png", ".sdata");
}


