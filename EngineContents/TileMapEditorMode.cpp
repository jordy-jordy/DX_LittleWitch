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
#include <EngineCore/Collision.h>
#include <EnginePlatform/EngineWindow.h>

#include "ContentsEditorGUI.h"

#include "GlobalVar.h"

#include "Tree.h"


enum class ESpawnList
{
	Tree0,
	Tree1,
	Tree2,
	Tree3,
	Tree4,
	Tree5,
	Tree6
};

enum class EEditMode
{
	TileMap,
	Object
};

class UTileMapWindow : public UEngineGUIWindow
{
public:

	//int SelectItem = 0;
	int ObjectItem = -1;
	UTileMapRenderer* TileMapRenderer = nullptr;
	EEditMode Mode = EEditMode::TileMap;

	int TileCountX = 20;
	int TileCountY = 15;
	int SelectTileIndex = 0;
	int SelectTreeIndex = 0;

	FVector TreeSize = { 1, 1 };

	std::vector<std::vector<int>> TileGroups = {
		{0, 1, 2, 3},
		{9, 10, 11, 12},
		{18, 19},
		{25, 35, 41, 51},
		{26, 36, 42, 52, 63},
		{27, 37, 43, 53, 64},
		{38, 44, 54, 65},
		{28, 39, 45, 55, 66},
		{29, 40, 46, 56},
		{4, 13, 20, 30},
		{5, 14, 21, 31},
		{6, 15, 22, 32},
		{7, 16, 23, 33},
		{8, 17, 24, 34},
		{47, 57, 67, 71},
		{48, 58, 68, 72},
		{49, 59},
		{60, 69},
		{61, 70},
		{50, 62},
		{75, 76, 86, 87},
		{77, 78, 88, 89},
		{79, 80, 81, 90, 91, 92},
		{73, 74, 82, 83, 84, 85, 93, 94, 95, 96, 97, 98, 99, 100},
		{107, 108, 109, 110, 111, 112, 120, 121, 122, 130, 131, 132},
		{133, 134, 135, 136, 145, 146, 147, 148, 153, 154, 155, 156, 157, 158, 159, 160},
		{113, 114, 123, 124},
		{115, 116, 125, 126},
		{117, 127},
		{118, 119, 128, 129},
		{137, 138, 149, 150},
		{143, 144, 151, 152},
		{101, 102, 103, 104, 105, 106}
		
	};


	//void TileMapMode()
	//{
	//	UEngineSprite* Sprite = TileMapRenderer->GetSprite();

	//	for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
	//	{
	//		UEngineTexture* Texture = Sprite->GetTexture(i);
	//		FSpriteData Data = Sprite->GetSpriteData(i);

	//		//SRV�Դϴ�
	//		ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

	//		std::string Text = std::to_string(i); // Ÿ�� �ε����� ���ڿ��� ��ȯ
	//		std::string TileName = "Tile_" + std::to_string(i); // Ÿ�� �̸� ����

	//		// �̹��� ���
	//		if (i != 0 && i % 4 == 0) // �� �ٿ� 17�� ���
	//		{
	//			ImGui::NewLine(); // �ٹٲ�
	//		}

	//		ImGui::BeginGroup(); // �׷� ����

	//		ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
	//		ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

	//		if (ImGui::ImageButton(Text.c_str(), SRV, { 32, 32 }, Pos, Size))
	//		{
	//			SelectTileIndex = static_cast<int>(i);
	//		}

	//		// �̸� ��� (�̹��� �Ʒ�)
	//		ImGui::Text(TileName.c_str());

	//		ImGui::EndGroup(); // �׷� ����

	//		ImGui::SameLine(); // ���� Ÿ�Ϸ� �̵�
	//	}

	//	// ���� TileMap ũ�� ���� �� Ÿ�� ���� �ڵ�
	//	ImGui::NewLine(); // ��ư ���� �Ʒ��� �̵�
	//	ImGui::InputInt("TileMapX", &TileCountX);
	//	ImGui::InputInt("TileMapY", &TileCountY);

	//	if (ImGui::Button("TileMap Create"))
	//	{
	//		for (int y = 0; y < TileCountY; y++)
	//		{
	//			for (int x = 0; x < TileCountX; x++)
	//			{
	//				TileMapRenderer->SetTile(x, y, SelectTileIndex);
	//			}
	//		}
	//	}

	//	if (true == UEngineInput::IsPress(VK_LBUTTON) && true != GEngine->GetMainWindow().IsMouseScreenOut())
	//	{
	//		FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
	//		ScreenPos.Z = ScreenPos.Y;

	//		TileMapRenderer->SetTile(ScreenPos, SelectTileIndex);
	//	}

	//	if (true == UEngineInput::IsPress(VK_RBUTTON) && true != GEngine->GetMainWindow().IsMouseScreenOut())
	//	{
	//		FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
	//		ScreenPos.Z = ScreenPos.Y;

	//		TileMapRenderer->RemoveTile(ScreenPos);
	//	}
	//}

	void TileMapMode()
	{
		UEngineSprite* Sprite = TileMapRenderer->GetSprite();

		for (size_t groupIndex = 0; groupIndex < TileGroups.size(); ++groupIndex)
		{
			ImGui::Text(("Group " + std::to_string(groupIndex + 1)).c_str());
			ImGui::Separator(); // �׷� ���м� ���

			for (size_t i = 0; i < TileGroups[groupIndex].size(); ++i)
			{
				int tileIndex = TileGroups[groupIndex][i];
				UEngineTexture* Texture = Sprite->GetTexture(tileIndex);
				FSpriteData Data = Sprite->GetSpriteData(tileIndex);

				// SRV�Դϴ�
				ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

				std::string Text = std::to_string(tileIndex);
				std::string TileName = "Tile_" + std::to_string(tileIndex);

				// �̹��� ���
				if (i != 0 && i % 5 == 0) // �� �ٿ� 5�� ���
				{
					ImGui::NewLine(); // �ٹٲ�
				}

				ImGui::BeginGroup(); // �׷� ����

				ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
				ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

				if (ImGui::ImageButton(Text.c_str(), SRV, { 32, 32 }, Pos, Size))
				{
					SelectTileIndex = tileIndex;
				}

				ImGui::Text(TileName.c_str());
				ImGui::EndGroup(); // �׷� ����
				ImGui::SameLine(); // ���� Ÿ�Ϸ� �̵�
			}
			ImGui::NewLine(); // ���� �׷����� �̵�
		}

		// ���� TileMap ũ�� ���� �� Ÿ�� ���� �ڵ�� ����
		ImGui::NewLine();
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

		// ���콺 Ŭ������ Ÿ�� ���� �ڵ�� �״�� ����
		if (true == UEngineInput::IsPress(VK_LBUTTON) && true != GEngine->GetMainWindow().IsMouseScreenOut())
		{
			FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

			TileMapRenderer->SetTile(ScreenPos, SelectTileIndex);
			TileMapRenderer->SetWorldLocation({ ScreenPos.X, ScreenPos.Y, ScreenPos.Y });
		}

		if (true == UEngineInput::IsPress(VK_RBUTTON) && true != GEngine->GetMainWindow().IsMouseScreenOut())
		{
			FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

			TileMapRenderer->RemoveTile(ScreenPos);
		}
	}


	void ObjectMode()
	{
		{
			 std::shared_ptr<UEngineSprite> SpriteName = UEngineSprite::Find<UEngineSprite>("Trees");
			 UEngineSprite* Sprite = SpriteName.get();

			for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
			{
				UEngineTexture* Texture = Sprite->GetTexture(i);
				FSpriteData Data = Sprite->GetSpriteData(i);

				//SRV�Դϴ�
				ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

				std::string Text = std::to_string(i);

				if (i != 0)
				{
					if (0 != (i % 6))
					{
						ImGui::SameLine();
					}
				}

				ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
				ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

				if (ImGui::ImageButton(Text.c_str(), SRV, { 60, 60 }, Pos, Size))
				{
					SelectTreeIndex = static_cast<int>(i);
				}
				// ���͸� ġ�� �ʴ°���.
			}

			if (true == UEngineInput::IsDown(VK_LBUTTON) && true != GEngine->GetMainWindow().IsMouseScreenOut())
			{
				ESpawnList SelectTree = static_cast<ESpawnList>(SelectTreeIndex);
				FVector Pos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
				Pos.Z = 0;

				std::shared_ptr<AFieldObjects> NewTree;

				switch (SelectTree)
				{
				case ESpawnList::Tree0:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 0);
					break;
				case ESpawnList::Tree1:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 1);
					break;
				case ESpawnList::Tree2:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 2);
					break;
				case ESpawnList::Tree3:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 3);
					break;
				case ESpawnList::Tree4:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 4);
					break;
				case ESpawnList::Tree5:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 5);
					break;
				case ESpawnList::Tree6:
					NewTree = GetWorld()->SpawnActor<ATree>("Tree");
					NewTree->GetRenderer()->SetSprite("Trees", 6);
					break;
				default:
					break;
				}

				NewTree->GetRenderer()->SpriteData.Pivot = { 0.5f, 0.15f };
				NewTree->SetActorLocation(Pos);
			}
		}

		{
			if (ImGui::Button("EditObjectDelete"))
			{
				std::list<std::shared_ptr<AFieldObjects>> AllTreeList = GetWorld()->GetAllActorListByClass<AFieldObjects>();
				for (std::shared_ptr<AFieldObjects> Tree : AllTreeList)
				{
					Tree->Destroy();
				}
			}
		}

		{
			std::vector<std::shared_ptr<AFieldObjects>> AllTreeList = GetWorld()->GetAllActorArrayByClass<AFieldObjects>();

			std::vector<std::string> ArrString;
			for (std::shared_ptr<class AActor> Actor : AllTreeList)
			{
				ArrString.push_back(Actor->GetName());
			}

			std::vector<const char*> Arr;
			for (size_t i = 0; i < ArrString.size(); i++)
			{
				Arr.push_back(ArrString[i].c_str());
			}


			if (0 < Arr.size())
			{
				ImGui::ListBox("AllActorList", &ObjectItem, &Arr[0], static_cast<int>(Arr.size()));

				if (ObjectItem != -1)
				{

				}

				if (true == ImGui::Button("Delete"))
				{
					AllTreeList[ObjectItem]->Destroy();
					ObjectItem = -1;
				}

			}
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
				std::list<std::shared_ptr<AFieldObjects>> AllTreeList = GetWorld()->GetAllActorListByClass<AFieldObjects>();

				UEngineSerializer Ser;

				Ser << static_cast<int>(AllTreeList.size());

				for (std::shared_ptr<AFieldObjects> Actor : AllTreeList)
				{

					Ser << static_cast<int>(Actor->TreeTypeValue);
					// ���� ����ȴٴ� �̾߱�
					Actor->Serialize(Ser);
				}

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

				int ObjectsCount = 0;

				Ser >> ObjectsCount;

				for (size_t i = 0; i < ObjectsCount; i++)
				{
					int TreeTypeValue = 0;
					Ser >> TreeTypeValue;

					ETreeType TreeType = static_cast<ETreeType>(TreeTypeValue);

					std::shared_ptr<AFieldObjects> NewTree = nullptr;

					switch (TreeType)
					{
					case ETreeType::Tree0:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 0);
						break;
					case ETreeType::Tree1:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 1);
						break;
					case ETreeType::Tree2:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 2);
						break;
					case ETreeType::Tree3:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 3);
						break;
					case ETreeType::Tree4:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 4);
						break;
					case ETreeType::Tree5:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 5);
						break;
					case ETreeType::Tree6:
						NewTree = GetWorld()->SpawnActor<ATree>();
						NewTree->GetRenderer()->SetSprite("Trees", 6);
						break;
					default:
						break;
					}

					NewTree->DeSerialize(Ser);
				}

				TileMapRenderer->DeSerialize(Ser);

			}
		}
	}

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
			ObjectMode();
			break;
		default:
			break;
		}

		SaveAndLoad();
	}
};


ATileMapEditorMode::ATileMapEditorMode()
{
	GetWorld()->CreateCollisionProfile("Tree");

	TileMapDirLoad();
	GetWorld()->CreateCollisionProfile("GUI");

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	FieldRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PivotSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	Renderer_Tile = CreateDefaultSubObject<UTileMapRenderer>();

	FieldRenderer->SetupAttachment(RootComponent);
	PivotSpriteRenderer->SetupAttachment(RootComponent);
	Renderer_Tile->SetupAttachment(RootComponent);
};


ATileMapEditorMode::~ATileMapEditorMode()
{

};


void ATileMapEditorMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// �� �̵� ���� Ȯ��

	float CameraSpeed = 500.0f;

	if (UEngineInput::IsPress('W'))
	{
		Camera->AddActorLocation({ 0.0f, 1.0f * CameraSpeed * _DeltaTime , 0.0f });
	}

	if (UEngineInput::IsPress('A'))
	{
		Camera->AddActorLocation({ -1.0f * CameraSpeed * _DeltaTime , 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		Camera->AddActorLocation({ 0.0f, -1.0f * CameraSpeed * _DeltaTime , 0.0f });
	}

	if (UEngineInput::IsPress('D'))
	{
		Camera->AddActorLocation({ 1.0f * CameraSpeed * _DeltaTime , 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		Camera->AddActorLocation({ 0.0f , 0.0f, -1.0f * CameraSpeed * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		Camera->AddActorLocation({ 0.0f , 0.0f, 1.0f * CameraSpeed * _DeltaTime });
	}

	Camera->GetCameraComponent()->SetZSort(0, true);

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

	FieldRenderer->SetTexture("Field_Green_002.png");
	FieldRenderer->SetScale3D(GreenFieldSize_Plus);
	FieldRenderer->SetWorldLocation({ GreenFieldSize_Plus.Half().X, GreenFieldSize_Plus.Half().Y, 10000.0f });

	PivotSpriteRenderer->SetRelativeScale3D({ 10.0f, 10.0f, 1.0f });
	PivotSpriteRenderer->SetWorldLocation({ 0.0f, 0.0f, 200.0f });

	FVector TileSize = FVector(16.0f, 16.0f) * ScaleRatio;
	Renderer_Tile->SetTileSetting(ETileMapType::Rect, "Wall_Default_0.png", TileSize, TileSize, { 0.0f, 0.0f });

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ HALF_WINDOW_SIZE.X, HALF_WINDOW_SIZE.Y, -100.0f, 0.0f });
	Camera->GetCameraComponent()->SetProjectionType(EProjectionType::Orthographic);
	Camera->GetCameraComponent()->SetFar(30000.0f);
	Camera->GetCameraComponent()->SetNear(-100.0f);
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
	TILEMAP_TILE_Dir.Append("Image\\WitchResource\\TILEMAP\\TILEMAP_TILE");
	std::vector<UEngineFile> TILES = TILEMAP_TILE_Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	for (size_t i = 0; i < TILES.size(); i++)
	{
		std::string TileFilePath = TILES[i].GetPathToString();
		UEngineTexture::Load(TileFilePath);
	}
	UEngineSprite::CreateSpriteToFolder(TILEMAP_TILE_Dir.GetPathToString());


	/*������Ʈ ���ҽ�*/
	UEngineDirectory TILEMAP_OBJECT_Dir;
	if (false == TILEMAP_OBJECT_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}
	UEngineDirectory TREE_Dir;
	if (false == TREE_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
		return;
	}

	TILEMAP_OBJECT_Dir.Append("Image\\WitchResource\\TILEMAP\\TILEMAP_OBJECTS");
	TREE_Dir.Append("Image\\WitchResource\\TILEMAP\\TILEMAP_OBJECTS\\Trees");

	std::vector<UEngineFile> OBJECTS = TILEMAP_OBJECT_Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });
	std::vector<UEngineFile> TREES = TREE_Dir.GetAllFile(true, { ".PNG", ".BMP", ".JPG" });

	for (size_t i = 0; i < OBJECTS.size(); i++)
	{
		std::string ObjectFilePath = OBJECTS[i].GetPathToString();

		UEngineTexture::Load(ObjectFilePath);
	}

	UEngineSprite::CreateSpriteToFolder(TREE_Dir.GetPathToString());

	UEngineSprite::CreateSpriteToMeta("Wall_Default_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Wall_Ramp_0.png", ".sdata");
	UEngineSprite::CreateSpriteToMeta("Wall_Stairs_0.png", ".sdata");

}


