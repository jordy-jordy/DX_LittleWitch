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

	FVector TreeSize = { 1, 1 };


protected:
	void LevelChangeStart() override;
	void BeginPlay();


private:
	class UTileMapWindow* TileMapWindow;
	class UTileMapRenderer* Renderer_Tile;
	class USpriteRenderer* PivotSpriteRenderer;
	class USpriteRenderer* FieldRenderer;

	class ACameraActor* Camera;
};
