#include "shTitleScene.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shPlayerController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shTitle.h"
#include "shPlayer.h"
#include "shInput.h"

namespace sh
{
	TitleScene::TitleScene()
	{

	}
	TitleScene::~TitleScene()
	{

	}
	void TitleScene::Initialize()
	{
		Title* title = new Title();
		AddGameObject(eLayerType::UI, title);
		title->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.1f));

	//UI Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		cameraComp->TurnLayerMask(eLayerType::BackGround, false);

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"LobbyScene");
		}

		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render()
	{
		Scene::Render();
	}
}