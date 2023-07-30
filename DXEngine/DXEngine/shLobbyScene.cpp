#include "shLobbyScene.h"
#include "shInput.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shPlayerController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
#include "shPlayer.h"
#include "shLobbyColumns.h"
#include "shFloors.h"
#include "shCollider2D.h"
#include "shAnimator.h"
#include "shLight.h"
#include "shLightingLogo.h"
#include "shCollisionManager.h"
#include "shRenderer.h"

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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);

		Light* light1 = object::newLight<Light>(Vector3(12.5f, 3.5f, object::zBackGround), eLightType::Spot, 10.0f, 30.0f);
		Light* light2 = object::newLight<Light>(Vector3(3.6f, -5.7f, object::zBackGround), eLightType::Point, 1.0f, 40.0f, Vector4(-60, -60, -60,1.0f));

		Player* Death
			= object::Instantiate<Player>(Vector4(0.0f, -3.6f, object::zPlayer, 0.4f), eLayerType::Player, L"SpriteAnimaionMaterial");
		
		Floors *floors
			= object::Instantiate<Floors>(Vector4(60.5f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floors->AddComponent<Collider2D>();

		LobbyColumns* columns
			= object::Instantiate<LobbyColumns>(Vector4(0, 0, object::zBackGround, 0), eLayerType::Ground, L"EmptyMaterial");

		{
			GameObject* lobby 
				= object::Instantiate<GameObject>(Vector4(0.0f, -2.9f, object::zBackGround, 1.5f), eLayerType::BackGround, L"LobbyMaterial");
			GameObject* office1
				= object::Instantiate<GameObject>(Vector4(47.2f, -1.6f, object::zBackGround, 1.1f), eLayerType::BackGround, L"OfficeMaterial");
			GameObject* office2
				= object::Instantiate<GameObject>(Vector4(69.7f, -1.6f, object::zBackGround, 1.1f), eLayerType::BackGround, L"OfficeMaterial");
		}

		{
			LightingLogo *lightingLogo
				= object::Instantiate<LightingLogo>(Vector4(-0.3f, 0.33f, object::zBackGround, 0.85f), eLayerType::Structure_B, L"LogoMaterial");

			GameObject* BossChair
				= object::Instantiate<GameObject>(Vector4(-0.5f, -2.0f, object::zBackGround, 0.7f), eLayerType::Structure_B, L"BossChairMaterial");
			GameObject* Stair_R
				= object::Instantiate<GameObject>(Vector4(7.0, -5.45f, object::zBackGround, 0.7f), eLayerType::Structure_B, L"StairR_Material");
			GameObject* SupportDesk
				= object::Instantiate<GameObject>(Vector4(-0.25f, -5.4f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"SupportDesk_Material");
			GameObject* BossDesk
				= object::Instantiate<GameObject>(Vector4(-0.2f, -3.8f, object::zBackGround, 0.6f), eLayerType::Structure_F, L"BossDeskMaterial");
		}

		{
			GameObject* tree
				= object::Instantiate<GameObject>(Vector4(30.6f, -3.2f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"TreeMaterial");
			GameObject* circlestair
				= object::Instantiate<GameObject>(Vector4(40.4f, -5.6f, object::zBackGround, 0.45f), eLayerType::Structure_F, L"CircleStairMaterial");
			
		
			{
				Light* light1 =
					object::newLight<Light>(Vector3(40.4f, -0.9f, object::zBackGround), eLightType::Point, 5.0f);
				Light* light2 =
					object::newLight<Light>(Vector3(40.4f, -1.0f, object::zBackGround), eLightType::Spot, 7.0f, 34.0f);
				GameObject* lamp1
					= object::Instantiate<GameObject>(Vector4(40.4f, 0.0f, object::zBackGround, 0.9f), eLayerType::Structure_F, L"lamp2Material");
				lamp1->GetComponent<MeshRenderer>()->SetColor(Vector4(169, 245, 225, 1.0f));
			}
			GameObject* wall
				= object::Instantiate<GameObject>(Vector4(57.5f, -2.8f, object::zBackGround, 0.7f), eLayerType::Structure_F, L"WallMaterial");
			GameObject* pillar
				= object::Instantiate<GameObject>(Vector3(72.0f, -2.0f, object::zBackGround),Vector2(0.7f, 0.7f), eLayerType::Structure_F, L"PillarMaterial");
		}
		
		{
			GameObject* light = new GameObject();
			light->SetName(L"Sun");
			AddGameObject(eLayerType::Light, light);
			Light* lightComp = light->AddComponent<Light>();
			lightComp->SetType(eLightType::Directional);
			lightComp->SetColor(Vector4(0, 0, 0, 1.0f));
		}

		//Camera* uCamera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
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