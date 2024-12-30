#include "PreCompile.h"
#include "TitleGameMode.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>

#include "TitleScene.h"

class TestWindow : public UEngineGUIWindow
{
public:
	void OnGUI() override
	{
		ImGui::Button("WindowButton");
		ImGui::SameLine(); // ÇÑ°£ ¶ç±â
		ImGui::Text("test");

	}
};

ATitleGameMode::ATitleGameMode()
{
	Title = GetWorld()->SpawnActor<ATitleScene>();
	//Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
	//Logo->GetRenderer()->SetSpriteData(4);

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	//UEngineGUI::CreateGUIWindow<TestWindow>("TestWindow");
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress(VK_SPACE))
	{
		UEngineCore::OpenLevel("PLAY");
	}

}