#pragma once
#include <EngineCore/GameMode.h>


// Ό³Έν :
class ATileMapEditor : public AGameMode
{
public:
	// constrcuter destructer
	ATileMapEditor();
	~ATileMapEditor();

	// delete Function
	ATileMapEditor(const ATileMapEditor& _Other) = delete;
	ATileMapEditor(ATileMapEditor&& _Other) noexcept = delete;
	ATileMapEditor& operator=(const ATileMapEditor& _Other) = delete;
	ATileMapEditor& operator=(ATileMapEditor&& _Other) noexcept = delete;

protected:

private:

};
