#include "shDungeonScene.h"
#include "shDungeonLobby.h"
#include "shGhostBoxes.h"
#include "shCameraController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
#include "shD_Floors.h"
#include "shStoneLoads.h"
#include "shStoneLoad.h"
#include "shDungeonColumns.h"
#include "shMeshRenderer.h"
#include "shInput.h"
#include "shLight.h"
#include "shRenderer.h"
#include "shRope.h"
#include "shCollisionManager.h"

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
		Camera* mCamera = object::newCamera<Camera>(eLayerType::Camera, L"MAIN");
		this->SetActiveCamera(mCamera);
		renderer::mainCamera = this->GetActiveCamera()->getCameraCont();

		{	//12.2
			GameObject* BackGround_Pattern0
				= object::Instantiate<GameObject>(Vector3(23.5f, 0.2f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern1
				= object::Instantiate<GameObject>(Vector3(35.7f, -1.2f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern2
				= object::Instantiate<GameObject>(Vector3(47.9f, 0.2f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern3
				= object::Instantiate<GameObject>(Vector3(60.1f, 0.2f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern4
				= object::Instantiate<GameObject>(Vector3(72.3f, 7.2f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern5
				= object::Instantiate<GameObject>(Vector3(81.2f, 2.0f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern6
				= object::Instantiate<GameObject>(Vector3(93.0f, 2.0f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* BackGround_Pattern7
				= object::Instantiate<GameObject>(Vector3(108.9f, -2.6f, object::zBackGround), Vector2(0.6f, 0.7f), eLayerType::BackGround, L"DungeonBackGround_Material");
			GameObject* RockBG1
				= object::Instantiate<GameObject>(Vector3(16.3, -2.9f, object::zBackGround), Vector2(2.5f, 2.0f), eLayerType::Structure_B, L"RockBG04_Material");
			GameObject* pillar1
				= object::Instantiate<GameObject>(Vector3(97.5f, -3.2f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_B, L"Pillar2Material");
			GameObject* pillar2
				= object::Instantiate<GameObject>(Vector3(101.0f, -6.4f, object::zBackGround), Vector2(0.9f, 0.9f), eLayerType::Structure_B, L"PillarMaterial");
			GameObject* pillar3
				= object::Instantiate<GameObject>(Vector3(102.7f, -7.4f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_B, L"Pillar2Material");
		}

		DungeonLobby* Dlobby
			= object::Instantiate<DungeonLobby>(Vector4(0.0f, -0.7f, object::zBackGround, 1.4f), eLayerType::BackGround, L"DungeonLobbyMaterial");
		GameObject* Box_NPC
			= object::Instantiate<GameObject>(Vector3(88.0f, -3.2f, object::zBackGround), Vector2(0.8f, 0.8f), eLayerType::Structure_B, L"box_NPC_Material");

		GhostBoxes *ghostboxes 
			= object::Instantiate<GhostBoxes>(Vector4(43.5f, -7.3f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox3Material");
		D_Floors* floors
			= object::Instantiate<D_Floors>(Vector4(0.0f, -4.7f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floors->AddComponent<Collider2D>();

		GameObject* BackRock
			= object::Instantiate<GameObject>(Vector3(14.5f, -6.2f, object::zBackGround), Vector2(1.1f, 1.1f), eLayerType::Structure_B, L"RockBG07_Material");

		StoneLoads *stonLoads
			= object::Instantiate<StoneLoads>(Vector4(15.0f, -5.2f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		stonLoads->AddComponent<Collider2D>();

		{
			StoneLoad* stoneLoad
				= object::Instantiate<StoneLoad>(Vector3(42.0f, -0.1f, object::zBackGround), Vector2(0.6f, 0.4f), eLayerType::Ground, L"SquareStone1Material");
			Rope* rope1
				= object::Instantiate<Rope>(Vector3(42.0f, -4.0f, object::zBackGround), Vector2(0.3f, 0.8f), eLayerType::Structure_F, L"RopeMaterial");
			rope1->GetComponent<MeshRenderer>()->SetColor(Vector4(255, 0, 0, 1.0f));
		}

		DungeonColumns *dungeonColumns
			= object::Instantiate<DungeonColumns>(Vector3(40.0, -7.2f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_B, L"Column2Material");
		
		GameObject* CircleGround
			= object::Instantiate<GameObject>(Vector4(21.0, -9.5f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"CircleGroundMaterial");

		GameObject* elevator
			= object::Instantiate<GameObject>(Vector4(110.0f, -7.4f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"Elevator_Material");

		{
			GameObject* light = new GameObject();
			light->SetName(L"Sun");
			AddGameObject(eLayerType::Light, light);
			Light* lightComp = light->AddComponent<Light>();
			lightComp->SetType(eLightType::Directional);
			lightComp->SetColor(Vector4(30, 30, 30, 1.0f));
		}


		{
			GameObject* light = new GameObject();
			AddGameObject(eLayerType::Light, light);
			Transform* Tr = light->GetComponent<Transform>();
			Tr->SetPosition(Vector3(-1.8f, -2.2f, object::zBackGround));

			Light* lightComp = light->AddComponent<Light>();
			lightComp->SetType(eLightType::Point);
			lightComp->SetColor(Vector4(169, 245, 225, 1.0f));
			lightComp->SetRadius(1.8f);
		}

		Camera* uCamera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
	}

	void DungeonScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"LobbyScene");
		}
	}

	void DungeonScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void DungeonScene::Render()
	{

	}
	void DungeonScene::OnEnter()
	{
		renderer::mainCamera = this->GetActiveCamera()->getCameraCont();
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Structure_F, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::NPC, true);
	}
	void DungeonScene::OnExit()
	{
		Scene::PlayerResetTransform();
	}
}