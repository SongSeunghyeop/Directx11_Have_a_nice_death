#include "shLobbyScene.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
#include "shPlayer.h"
#include "shLobby.h"
#include "shOffice.h"
#include "shRock.h"
#include "shWall.h"
#include "shPillar.h"
#include "shPlaza.h"
#include "shCircleStair.h"
#include "shMeshRenderer.h"

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
			= object::Instantiate<Player>(Vector4(0.0f, -3.5f, object::zPlayer,0.7f), eLayerType::Player, L"PlayerMaterial");
		Lobby* lobby 
			= object::Instantiate<Lobby>(Vector4(0.0f, -2.9f, object::zBackGround, 1.45f), eLayerType::BackGround, L"LobbyMaterial");
		Plaza* plaza
			= object::Instantiate<Plaza>(Vector4(18.0f, -6.0f, object::zBackGround,1.45f), eLayerType::Ground, L"GroundMaterial");
		Office* office
			= object::Instantiate<Office>(Vector4(45.0f, -1.5f, object::zBackGround, 1.0f), eLayerType::BackGround, L"OfficeMaterial");


		Camera* mCamera = object::newCamera<Camera>(eLayerType::Camera, L"MAIN");
		mCamera->SetTarget(Death);
		Camera* uCamera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
	}

	void LobbyScene::Update()
	{
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