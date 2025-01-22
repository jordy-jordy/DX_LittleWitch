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

	void SetCurField(std::shared_ptr<class AAllField> _CurField);
	void SetFieldColImageName();


protected:
	void Tick(float _DeltaTime);
	void BeginPlay();

private:
	class APlayer* Player;
	std::shared_ptr<class AAllField> Field_Green;
	std::shared_ptr<class AAllField> Field_Home;
	std::shared_ptr<class AAllField> CurField;

	FieldList Field = FieldList::HOME;
	std::string_view FieldFolderName = "02_Field";
	std::string_view FieldColImageName = "Field_Home_001.png";

};
