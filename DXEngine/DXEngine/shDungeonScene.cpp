#include "shDungeonScene.h"
#include "shDungeonLobby.h"
#include "shD_Part1.h"
#include "shD_Part2.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
#include "shPlayer.h"
#include "shMeshRenderer.h"

namespace sh
{
	DungeonScene::DungeonScene()
	{

	}
	DungeonScene::~DungeonScene()
	{

	}
	void DungeonScene::Initialize()
	{
		Player* Death
			= object::Instantiate<Player>(Vector4(0.0f, -4.0f, object::zPlayer, 0.5f), eLayerType::Player, L"SpriteAnimaionMaterial");

		DungeonLobby* Dlobby	
			= object::Instantiate<DungeonLobby>(Vector4(0.0f, -0.7f, object::zBackGround, 1.4f), eLayerType::BackGround, L"DungeonLobbyMaterial");
	
		D_Part1* stoneLoad1
			= object::Instantiate<D_Part1>(Vector4(15.0f, -5.2f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");

		D_Part2* corne3
			= object::Instantiate<D_Part2>(Vector4(49.49, -7.4f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne2Material");
		
		Camera* uCamera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
		Camera* mCamera = object::newCamera<Camera>(eLayerType::Camera, L"MAIN");
		mCamera->SetTarget(Death);
	}

	void DungeonScene::Update()
	{
		Scene::Update();
	}

	void DungeonScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void DungeonScene::Render()
	{

	}
}