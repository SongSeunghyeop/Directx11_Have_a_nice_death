#include "shLobbyScene.h"
#include "shInput.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shPlayerController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
#include "shPlayer.h"
#include "shLobby.h"
#include "shOffice.h"
#include "shPlaza.h"
#include "shCollider2D.h"
#include "shAnimator.h"

namespace sh
{
	LobbyScene::LobbyScene()
	{

	}
	LobbyScene::~LobbyScene()
	{

	}
	void LobbyScene::Initialize()
	{
		Player* Death
			= object::Instantiate<Player>(Vector4(0.0f, -3.6f, object::zPlayer, 0.5f), eLayerType::Player, L"SpriteAnimaionMaterial");

		Lobby* lobby 
			= object::Instantiate<Lobby>(Vector4(0.0f, -2.9f, object::zBackGround, 1.5f), eLayerType::BackGround, L"LobbyMaterial");
		Office* office
			= object::Instantiate<Office>(Vector4(47.0f, -1.8f, object::zBackGround, 1.0f), eLayerType::BackGround, L"OfficeMaterial");
		Plaza* plaza
			= object::Instantiate<Plaza>(Vector4(18.5f, -6.2f, object::zBackGround,1.5f), eLayerType::Ground, L"GroundMaterial");

		Camera* uCamera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
		Camera* mCamera = object::newCamera<Camera>(eLayerType::Camera, L"MAIN");
		mCamera->SetTarget(Death);
	}

	void LobbyScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"DungeonScene");
		}

		Scene::Update();
	}

	void LobbyScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void LobbyScene::Render()
	{

	}
}