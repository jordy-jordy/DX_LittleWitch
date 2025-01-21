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

	void TileMapMode()
	{
		UEngineSprite* Sprite = TileMapRenderer->GetSprite();

		for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
		{
			UEngineTexture* Texture = Sprite->GetTexture(i);
			FSpriteData Data = Sprite->GetSpriteData(i);

			//SRV입니다
			ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

			std::string Text = std::to_string(i); // 타일 인덱스를 문자열로 변환
			std::string TileName = "Tile_" + std::to_string(i); // 타일 이름 생성

			// 이미지 출력
			if (i != 0 && i % 4 == 0) // 한 줄에 17개 출력
			{
				ImGui::NewLine(); // 줄바꿈
			}

			ImGui::BeginGroup(); // 그룹 시작

			ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
			ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

			if (ImGui::ImageButton(Text.c_str(), SRV, { 32, 32 }, Pos, Size))
			{
				SelectTileIndex = static_cast<int>(i);
			}

			// 이름 출력 (이미지 아래)
			ImGui::Text(TileName.c_str());

			ImGui::EndGroup(); // 그룹 종료

			ImGui::SameLine(); // 다음 타일로 이동
		}

		// 기존 TileMap 크기 설정 및 타일 생성 코드
		ImGui::NewLine(); // 버튼 영역 아래로 이동
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

	void ObjectMode()
	{
		{
			 std::shared_ptr<UEngineSprite> SpriteName = UEngineSprite::Find<UEngineSprite>("Trees");
			 UEngineSprite* Sprite = SpriteName.get();

			for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
			{
				UEngineTexture* Texture = Sprite->GetTexture(i);
				FSpriteData Data = Sprite->GetSpriteData(i);

				//SRV입니다
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
				// 엔터를 치지 않는개념.
			}

			if (true == UEngineInput::IsDown(VK_LBUTTON))
			{
				ESpawnList SelectTree = static_cast<ESpawnList>(SelectTreeIndex);
				FVector Pos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
				Pos.Z = 0.0f;

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
				MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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
					// 여기 저장된다는 이야기
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
				MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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

	PivotSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PivotSpriteRenderer->SetRelativeScale3D({ 10.0f, 10.0f, 1.0f });

	Renderer_Tile = CreateDefaultSubObject<UTileMapRenderer>();
	Renderer_Tile->SetTileSetting(ETileMapType::Rect, "Wall_Default_0.png", { 16.0f * ScaleRatio, 16.0f * ScaleRatio }, { 16.0f * ScaleRatio, 16.0f * ScaleRatio }, { 0.0f, 0.0f });

	PivotSpriteRenderer->SetupAttachment(RootComponent);
	Renderer_Tile->SetupAttachment(RootComponent);

	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ HALF_WINDOW_SIZE.X, HALF_WINDOW_SIZE.Y, -100.0f, 0.0f });
	Camera->GetCameraComponent()->SetProjectionType(EProjectionType::Orthographic);
	Camera->GetCameraComponent()->SetZSort(0, true);
};


ATileMapEditorMode::~ATileMapEditorMode()
{

};


void ATileMapEditorMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// 휠 이동 방향 확인

	float CameraSpeed = 5550.0f;

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
	/*16x16 타일 리소스*/
	UEngineDirectory TILEMAP_TILE_Dir;
	if (false == TILEMAP_TILE_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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


	/*오브젝트 리소스*/
	UEngineDirectory TILEMAP_OBJECT_Dir;
	if (false == TILEMAP_OBJECT_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	UEngineDirectory TREE_Dir;
	if (false == TREE_Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
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


