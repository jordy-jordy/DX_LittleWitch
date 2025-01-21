#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class ATileMapEditorMode : public AGameMode
{
public:
	// constrcuter destructer
	ATileMapEditorMode();
	~ATileMapEditorMode();

	// delete Function
	ATileMapEditorMode(const ATileMapEditorMode& _Other) = delete;
	ATileMapEditorMode(ATileMapEditorMode&& _Other) noexcept = delete;
	ATileMapEditorMode& operator=(const ATileMapEditorMode& _Other) = delete;
	ATileMapEditorMode& operator=(ATileMapEditorMode&& _Other) noexcept = delete;

	void TileMapDirLoad();
	
	void Tick(float _DeltaTime);

protected:
	void LevelChangeStart() override;
	void BeginPlay();


private:
	std::shared_ptr<class UTileMapWindow> TileMapWindow;
	std::shared_ptr<class UTileMapRenderer> Renderer_Tile;
	std::shared_ptr<class USpriteRenderer> PivotSpriteRenderer;
	std::shared_ptr<class USpriteRenderer> FieldRenderer;

	std::shared_ptr<class ACameraActor> Camera;
};
