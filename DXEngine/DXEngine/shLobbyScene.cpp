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
		lobby->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 2.0f));

		Lobby* lobby2 = new Lobby();
		AddGameObject(eLayerType::BackGround, lobby2);
		lobby2->GetComponent<Transform>()->SetPosition(Vector3(30.0f, 0.0f, 2.0f));

		Office* office0 = new Office();
		AddGameObject(eLayerType::Monster, office0);
		office0->GetComponent<Transform>()->SetPosition(Vector3(30.0f, 0.0f, 2.0f));

		Office* office1 = new Office();
		AddGameObject(eLayerType::BackGround, office1);
		office1->GetComponent<Transform>()->SetPosition(Vector3(42.0f, 0.0f, 2.0f));

		Office* office2 = new Office();
		AddGameObject(eLayerType::BackGround, office2);
		office2->GetComponent<Transform>()->SetPosition(Vector3(54.0f, 0.0f, 2.0f));

		Column* colume = new Column();
		colume->SetName(L"Colume");
		AddGameObject(eLayerType::Structure, colume);
		colume->GetComponent<Transform>()->SetPosition(Vector3(5.0f, -0.5f, 1.0f));

		Player* Death = new Player();
		Death->SetName(L"Player");
		AddGameObject(eLayerType::Player, Death);
		Death->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		Death->AddComponent<PlayerController>();

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
		uCameraComp->TurnLayerMask(eLayerType::Structure, false);
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