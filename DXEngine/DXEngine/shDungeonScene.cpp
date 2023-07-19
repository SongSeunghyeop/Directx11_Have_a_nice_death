#include "shDungeonScene.h"
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
			= object::Instantiate<Player>(Vector4(0.0f, -4.0f, object::zPlayer, 0.5f), eLayerType::Player, L"PlayerMaterial");
		GameObject* lobby	
			= object::Instantiate<GameObject>(Vector4(0.0f, -0.7f, object::zBackGround, 1.4f), eLayerType::BackGround, L"DungeonLobbyMaterial");
		GameObject* bigspot
			= object::Instantiate<GameObject>(Vector4(4.4f, 1.7f, object::zBackGround, 1.1f), eLayerType::Structure_F, L"BigSpotMaterial");

		GameObject* ground1
			= object::Instantiate<GameObject>(Vector4(-2.0f, -5.6f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		GameObject* ground2
			= object::Instantiate<GameObject>(Vector4(-22.0f, -5.6f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");

		GameObject* broken_Ev
			= object::Instantiate<GameObject>(Vector4(-13.0f, -2.9f, object::zBackGround, 1.2f), eLayerType::Structure_F, L"Broken_ElevatorMaterial");
		GameObject* logo
			= object::Instantiate<GameObject>(Vector4(5.1f, -0.3f, object::zBackGround, 1.2f), eLayerType::Structure_F, L"LogoMaterial");
		GameObject* deskWall
			= object::Instantiate<GameObject>(Vector4(4.9f, -4.2f, object::zBackGround, 1.3f), eLayerType::Structure_B, L"DeskWallMaterial");
		GameObject* desk
			= object::Instantiate<GameObject>(Vector4(4.8f, -4.3f, object::zBackGround, 1.2f), eLayerType::Structure_B, L"DeskMaterial");

		GameObject* weapons
			= object::Instantiate<GameObject>(Vector4(-1.8f, -3.0f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"WeaponsMaterial");
		GameObject* skull1
			= object::Instantiate<GameObject>(Vector4(-1.8f, -1.9f, object::zBackGround, 1.1f), eLayerType::Structure_F, L"Skull1Material");
		GameObject* skull2
			= object::Instantiate<GameObject>(Vector4(-1.8f, -4.6f, object::zBackGround, 1.1f), eLayerType::Structure_B, L"Skull2Material");

		GameObject* SmallColumnDown
			= object::Instantiate<GameObject>(Vector4(12.0f, -3.8f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"ColumnDownMaterial");
		GameObject* BigColumnDown
			= object::Instantiate<GameObject>(Vector4(13.0f, -4.5f, object::zPlayer, 0.9f), eLayerType::Structure_F, L"ColumnDownMaterial");

		GameObject* stoneLoad1
			= object::Instantiate<GameObject>(Vector4(15.0f, -5.2f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* corne1
			= object::Instantiate<GameObject>(Vector4(16.9f, -5.19f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne1Material");
		GameObject* stoneLoad2
			= object::Instantiate<GameObject>(Vector3(16.85f, -6.3f, object::zBackGround),Vector2(0.4f,0.25f), eLayerType::Structure_B, L"SquareStone2Material");
		

		GameObject* CircleGround
			= object::Instantiate<GameObject>(Vector4(21.0, -9.5f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"CircleGroundMaterial");
		GameObject* stoneLoad3
			= object::Instantiate<GameObject>(Vector4(19.2, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad4
			= object::Instantiate<GameObject>(Vector4(23.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad5
			= object::Instantiate<GameObject>(Vector4(27.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* corne2
			= object::Instantiate<GameObject>(Vector4(29.1f, -7.39f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne1Material");
		GameObject* stoneLoad6
			= object::Instantiate<GameObject>(Vector3(29.1f, -8.0f, object::zBackGround), Vector2(0.4, 0.17f), eLayerType::Structure_F, L"SquareStone2Material");
		GameObject* stoneLoad7
			= object::Instantiate<GameObject>(Vector4(31.0, -8.5f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad8
			= object::Instantiate<GameObject>(Vector4(35.0, -8.5f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad9
			= object::Instantiate<GameObject>(Vector4(39.0, -8.5f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad10
			= object::Instantiate<GameObject>(Vector4(43.0, -8.5f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad11
			= object::Instantiate<GameObject>(Vector4(47.0, -8.5f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");

		GameObject* column1
			= object::Instantiate<GameObject>(Vector3(40.0, -7.3f, object::zBackGround),Vector2(0.5f,0.9f), eLayerType::Structure_B, L"Column2Material");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector3(45.0, -7.0f, object::zBackGround), Vector2(0.6f, 1.2f), eLayerType::Structure_B, L"Column2Material");
		
		GameObject* corne3
			= object::Instantiate<GameObject>(Vector4(49.49, -7.4f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne2Material");
		GameObject* stoneLoad12
			= object::Instantiate<GameObject>(Vector3(49.5, -8.5f, object::zBackGround),Vector2(0.4f,0.17f), eLayerType::Structure_B, L"SquareStone3Material");
		GameObject* stoneLoad13
			= object::Instantiate<GameObject>(Vector3(52.2, -7.43f, object::zBackGround),Vector2(0.6f,0.4f), eLayerType::Structure_B, L"SquareStone1Material");

		GameObject* column3
			= object::Instantiate<GameObject>(Vector3(50.5, -6.0f, object::zBackGround), Vector2(0.5f,0.8f), eLayerType::Structure_B, L"Column3Material");
		GameObject* column4
			= object::Instantiate<GameObject>(Vector3(51.5, -6.0f, object::zBackGround), Vector2(0.5f, 0.8f), eLayerType::Structure_B, L"Column3Material");

		GameObject* stoneLoad15
			= object::Instantiate<GameObject>(Vector3(55.0, -5.8f, object::zBackGround),Vector2(0.4f,0.35f), eLayerType::Structure_B, L"SquareStone3Material");
		GameObject* corne4
			= object::Instantiate<GameObject>(Vector4(54.97, -4.2f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne2Material");
		GameObject* stoneLoad16
			= object::Instantiate<GameObject>(Vector4(56.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad17
			= object::Instantiate<GameObject>(Vector4(60.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad18
			= object::Instantiate<GameObject>(Vector4(64.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* column5
			= object::Instantiate<GameObject>(Vector3(58.0f, -3.0f, object::zBackGround), Vector2(0.5f, 1.0f), eLayerType::Structure_F, L"Column2Material");
		GameObject* stoneLoad19
			= object::Instantiate<GameObject>(Vector4(67.0f, -5.8f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone2Material");
		GameObject* stoneLoad20
			= object::Instantiate<GameObject>(Vector3(68.0f, -7.75f, object::zBackGround), Vector2(0.3f, 0.65f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* stoneLoad21
			= object::Instantiate<GameObject>(Vector3(72.5f, -8.5f, object::zBackGround), Vector2(1.0f, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad22
			= object::Instantiate<GameObject>(Vector3(81.5f, -7.75f, object::zBackGround), Vector2(1.0f, 0.65f), eLayerType::Structure_F, L"SquareStone1Material");

		GameObject* elevator
			= object::Instantiate<GameObject>(Vector4(81.0, -5.5f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"Elevator_Material");
		
		{
			GameObject* groundFill1
				= object::Instantiate<GameObject>(Vector4(23.0f, -14.0f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill2
				= object::Instantiate<GameObject>(Vector4(35.2f, -15.0f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill3
				= object::Instantiate<GameObject>(Vector4(47.4f, -15.0f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill4
				= object::Instantiate<GameObject>(Vector4(55.5f, -13.5f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill5
				= object::Instantiate<GameObject>(Vector4(61.2f, -10.7f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill6
				= object::Instantiate<GameObject>(Vector4(73.4f, -15.0f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
			GameObject* groundFill7
				= object::Instantiate<GameObject>(Vector4(83.7f, -14.0f, object::zBackGround, 1.2f), eLayerType::BackGround, L"GroundFillMaterial");
		}


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