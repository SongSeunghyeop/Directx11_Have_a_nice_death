#include "shPlayScene.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shPlayerController.h"
#include "shCamera.h"
#include "shPlayer.h"
#include "shLobby.h"
#include "shObject.h"

namespace sh
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}
	void PlayScene::Initialize()
	{
		Death = object::Instantiate<Player>(sh::enums::eLayerType::Player);
		backGround = object::Instantiate<Lobby>(sh::enums::eLayerType::BackGround);

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->AddComponent<Camera>();
		camera->AddComponent<CameraController>();
		CameraController* cameraCont = camera->GetComponent<CameraController>();
		cameraCont->setTarget(Death);

		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}
}