#pragma once
#include <EngineCore/GameMode.h>


enum class FieldList
{
	NONE = 0,
	HOME = 1,
	GREEN = 2,
	MAX
};

// Ό³Έν :
class APlayGameMode : public AGameMode
{
public:
	// constrcuter destructer
	APlayGameMode();
	~APlayGameMode();

	// delete Function
	APlayGameMode(const APlayGameMode& _Other) = delete;
	APlayGameMode(APlayGameMode&& _Other) noexcept = delete;
	APlayGameMode& operator=(const APlayGameMode& _Other) = delete;
	APlayGameMode& operator=(APlayGameMode&& _Other) noexcept = delete;

	void PlayDirLoad();
	void PlaySpritesInit();

	void SetCurField(class AAllField* _CurField);

	void ChangeField(float _DeltaTime);


protected:
	void Tick(float _DeltaTime);
	void BeginPlay();

private:
	class APlayer* Player;
	class AAllField* Field_Green;
	class AAllField* Field_Home;
	class AAllField* CurField;

	FieldList Field = FieldList::NONE;
	std::string_view FieldFolderName = "02_Field";
	std::string_view FieldColImageName;

};
