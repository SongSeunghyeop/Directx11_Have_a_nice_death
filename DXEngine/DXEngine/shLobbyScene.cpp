#include "shLobbyScene.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shPlayerController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shPlayer.h"
#include "shLobby.h"
#include "shOffice.h"
#include "shColumn.h"
#include "shRock.h"
#include "shGround.h"
#include "shTree.h"
#include "shWall.h"

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
		Lobby* lobby = new Lobby();
		AddGameObject(eLayerType::BackGround, lobby);
		lobby->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.65f, 1.0f));
		lobby->GetComponent<Transform>()->SetScale(Vector3(16.4f, 8.4f, .0f));

		Player* Death = new Player();
		Death->SetName(L"Player");
		AddGameObject(eLayerType::Player, Death);
		Death->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.5f));
		Death->GetComponent<Transform>()->SetScale(Vector3(0.6f, 0.6f, .0f));
		Death->AddComponent<PlayerController>();

		Column* Colume_b1 = new Column();
		Colume_b1->SetName(L"Colume_b1");
		AddGameObject(eLayerType::Structure_B, Colume_b1);
		Colume_b1->GetComponent<Transform>()->SetPosition(Vector3(7.2f, 0.65f, 0.4f));
		Colume_b1->GetComponent<Transform>()->SetScale(Vector3(1.8f, 6.6f, .0f));

		Rock* B_Rock = new Rock();
		AddGameObject(eLayerType::BackGround, B_Rock);
		B_Rock->GetComponent<Transform>()->SetPosition(Vector3(10.0f, 0.0f, 1.0f));
		B_Rock->GetComponent<Transform>()->SetScale(Vector3(6.0f, 6.0f, .0f));

		Ground* ground = new Ground();
		AddGameObject(eLayerType::BackGround, ground);
		ground->GetComponent<Transform>()->SetPosition(Vector3(9.1f, -1.3f, 0.9f));

		ground->GetComponent<Transform>()->SetScale(Vector3(15.0f, 1.0f, .0f));

		Tree* tree = new Tree();
		AddGameObject(eLayerType::Structure_B, tree);
		tree->GetComponent<Transform>()->SetPosition(Vector3(19.6f, 0.2f, 0.7f));
		tree->GetComponent<Transform>()->SetScale(Vector3(3.0f, 3.0f, .0f));

		Office* office0 = new Office();
		AddGameObject(eLayerType::Monster, office0);
		office0->GetComponent<Transform>()->SetPosition(Vector3(26.0f, 0.0f, 1.0f));
		office0->GetComponent<Transform>()->SetScale(Vector3(9.0f, 5.0f, .0f));

		Column* Colume_f2 = new Column();
		Colume_f2->SetName(L"Colume_f2");
		AddGameObject(eLayerType::Structure_F, Colume_f2);
		Colume_f2->GetComponent<Transform>()->SetPosition(Vector3(31.0f, 0.5f, 0.0f));
		Colume_f2->GetComponent<Transform>()->SetScale(Vector3(2.0f, 8.0f, .0f));

		Wall* wall = new Wall();
		AddGameObject(eLayerType::Structure_B, wall);
		wall->GetComponent<Transform>()->SetPosition(Vector3(35.0, -1.0f, 1.0f));
		wall->GetComponent<Transform>()->SetScale(Vector3(5.0f, 5.0f, .0f));

		Column* Colume_f3 = new Column();
		Colume_f3->SetName(L"Colume_f3");
		AddGameObject(eLayerType::Structure_F, Colume_f3);
		Colume_f3->GetComponent<Transform>()->SetPosition(Vector3(39.0f, 0.5f, 0.0f));
		Colume_f3->GetComponent<Transform>()->SetScale(Vector3(2.0f, 8.0f, .0f));

		Office* office1 = new Office();
		AddGameObject(eLayerType::Monster, office1);
		office1->GetComponent<Transform>()->SetPosition(Vector3(40.0f, 0.0f, 1.0f));
		office1->GetComponent<Transform>()->SetScale(Vector3(9.0f, 5.0f, .0f));

		//Main Camera
		GameObject* mCamera = new GameObject();
		AddGameObject(eLayerType::Camera, mCamera);
		mCamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* mCameraComp = mCamera->AddComponent<Camera>();
		mCameraComp->TurnLayerMask(eLayerType::UI, false);
		CameraController * mCameraController = mCamera->AddComponent<CameraController>();
		mCameraController->SetTarget(Death);

		//UI Camera
		GameObject* uCamera = new GameObject();
		AddGameObject(eLayerType::Camera, uCamera);
		uCamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* uCameraComp = uCamera->AddComponent<Camera>();
		uCameraComp->TurnLayerMask(eLayerType::BackGround, false);
		uCameraComp->TurnLayerMask(eLayerType::Structure_F, false);
		uCameraComp->TurnLayerMask(eLayerType::Structure_B, false);
		uCameraComp->TurnLayerMask(eLayerType::Player, false);

		Scene::Initialize();
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
		Scene::Render();
	}
}