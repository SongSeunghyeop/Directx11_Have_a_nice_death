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
#include "shPillar.h"
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
		Lobby* lobby = new Lobby();
		AddGameObject(eLayerType::BackGround, lobby);
		lobby->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.7f, 1.0f));
		lobby->GetComponent<Transform>()->SetScale(Vector3(16.4f, 8.3f, .0f));

		GameObject* BossChair = new GameObject();
		BossChair->SetName(L"BossChair");
		AddGameObject(eLayerType::Structure_B, BossChair);
		MeshRenderer* mr = BossChair->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"BossChairMaterial"));
		BossChair->GetComponent<Transform>()->SetPosition(Vector3(-0.4f, 1.2f, 0.9f));
		BossChair->GetComponent<Transform>()->SetScale(Vector3(1.3f, 1.9f, .0f));
		BossChair->Initialize();

		GameObject* BossDesk = new GameObject();
		BossDesk->SetName(L"BossDesk");
		AddGameObject(eLayerType::Structure_B, BossDesk);
		MeshRenderer* mr2 = BossDesk->AddComponent<MeshRenderer>();
		mr2->SetMaterial(Resources::Find<Material>(L"BossDeskMaterial"));
		BossDesk->GetComponent<Transform>()->SetPosition(Vector3(-0.1f, 0.2f, 0.6f));
		BossDesk->GetComponent<Transform>()->SetScale(Vector3(2.7f, 1.6f, .0f));
		BossDesk->Initialize();

		GameObject* SupportDesk = new GameObject();
		SupportDesk->SetName(L"SupportDesk");
		AddGameObject(eLayerType::Structure_B, SupportDesk);
		MeshRenderer* mr3 = SupportDesk->AddComponent<MeshRenderer>();
		mr3->SetMaterial(Resources::Find<Material>(L"SupportDesk_Material"));
		SupportDesk->GetComponent<Transform>()->SetPosition(Vector3(-0.2f, -0.65f, 0.7f));
		SupportDesk->GetComponent<Transform>()->SetScale(Vector3(5.2f, 1.4, .0f));
		SupportDesk->Initialize();

		GameObject* Stair_R = new GameObject();
		Stair_R->SetName(L"Stair_R");
		AddGameObject(eLayerType::Structure_B, Stair_R);
		MeshRenderer* mr4 = Stair_R->AddComponent<MeshRenderer>();
		mr4->SetMaterial(Resources::Find<Material>(L"StairR_Material"));
		Stair_R->GetComponent<Transform>()->SetPosition(Vector3(3.3f, -0.7f, 0.8f));
		Stair_R->GetComponent<Transform>()->SetScale(Vector3(2.7f, 1.1f, .0f));
		Stair_R->Initialize();

		Player* Death = new Player();
		Death->SetName(L"Player");
		AddGameObject(eLayerType::Player, Death);
		Death->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.4f));
		Death->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.5f, .0f));
		Death->AddComponent<PlayerController>();

		Column* Colume_b1 = new Column();
		Colume_b1->SetName(L"Colume_b1");
		AddGameObject(eLayerType::Structure_B, Colume_b1);
		Colume_b1->GetComponent<Transform>()->SetPosition(Vector3(7.2f, 0.65f, 0.0f));
		Colume_b1->GetComponent<Transform>()->SetScale(Vector3(1.8f, 6.6f, .0f));

		Column* Colume_f1 = new Column();
		Colume_f1->SetName(L"Colume_f1");
		AddGameObject(eLayerType::Structure_F, Colume_f1);
		Colume_f1->GetComponent<Transform>()->SetPosition(Vector3(8.2f, 0.2f, 0.8f));
		Colume_f1->GetComponent<Transform>()->SetScale(Vector3(1.0f, 3.5f, .0f));

		Rock* B_Rock = new Rock();
		AddGameObject(eLayerType::BackGround, B_Rock);
		B_Rock->GetComponent<Transform>()->SetPosition(Vector3(10.0f, 0.0f, 1.0f));
		B_Rock->GetComponent<Transform>()->SetScale(Vector3(6.0f, 6.0f, .0f));

		Ground* ground1 = new Ground();
		AddGameObject(eLayerType::BackGround, ground1);
		ground1->GetComponent<Transform>()->SetPosition(Vector3(9.6f, -1.0f, 0.6f));
		ground1->GetComponent<Transform>()->SetScale(Vector3(16.0f, 0.7f, .0f));

		Ground* ground2 = new Ground();
		AddGameObject(eLayerType::BackGround, ground2);
		ground2->GetComponent<Transform>()->SetPosition(Vector3(21.0f, -1.0f, 0.7f));
		ground2->GetComponent<Transform>()->SetScale(Vector3(16.0f, 0.7f, .0f));

		Ground* ground3 = new Ground();
		AddGameObject(eLayerType::BackGround, ground3);
		ground3->GetComponent<Transform>()->SetPosition(Vector3(34.5f, -1.0f, 0.7f));
		ground3->GetComponent<Transform>()->SetScale(Vector3(16.0f, 0.7f, .0f));

		Tree* tree = new Tree();
		AddGameObject(eLayerType::Structure_B, tree);
		tree->GetComponent<Transform>()->SetPosition(Vector3(16.7f, 0.6f, 0.5f));
		tree->GetComponent<Transform>()->SetScale(Vector3(3.0f, 3.0f, .0f));

		CircleStair* circlestair = new CircleStair();
		AddGameObject(eLayerType::Structure_B, circlestair);
		circlestair->GetComponent<Transform>()->SetPosition(Vector3(22.0f, -0.8f, 0.6f));
		circlestair->GetComponent<Transform>()->SetScale(Vector3(2.5f, 0.5f, .0f));

		Column* Colume_f2 = new Column();
		Colume_f2->SetName(L"Colume_f2");
		AddGameObject(eLayerType::Structure_F, Colume_f2);
		Colume_f2->GetComponent<Transform>()->SetPosition(Vector3(18.5f, -0.3f, 0.0f));
		Colume_f2->GetComponent<Transform>()->SetScale(Vector3(0.8f, 2.5f, .0f));

		Office* office0 = new Office();
		AddGameObject(eLayerType::Monster, office0);
		office0->GetComponent<Transform>()->SetPosition(Vector3(23.0f, 1.0f, 1.0f));
		office0->GetComponent<Transform>()->SetScale(Vector3(9.0f, 5.0f, .0f));

		Column* Colume_f3 = new Column();
		Colume_f3->SetName(L"Colume_f3");
		AddGameObject(eLayerType::Structure_F, Colume_f3);
		Colume_f3->GetComponent<Transform>()->SetPosition(Vector3(28.0, 0.5f, 0.0f));
		Colume_f3->GetComponent<Transform>()->SetScale(Vector3(1.9f, 7.0f, .0f));

		Wall* wall = new Wall();
		AddGameObject(eLayerType::Structure_B, wall);
		wall->GetComponent<Transform>()->SetPosition(Vector3(32.0, 0.9f, 0.6f));
		wall->GetComponent<Transform>()->SetScale(Vector3(4.5f, 4.5f, .0f));

		Column* Colume_f4 = new Column();
		Colume_f4->SetName(L"Colume_f4");
		AddGameObject(eLayerType::Structure_F, Colume_f4);
		Colume_f4->GetComponent<Transform>()->SetPosition(Vector3(36.3, 0.5f, 0.0f));
		Colume_f4->GetComponent<Transform>()->SetScale(Vector3(1.9f, 7.0f, .0f));

		Office* office1 = new Office();
		AddGameObject(eLayerType::BackGround, office1);
		office1->GetComponent<Transform>()->SetPosition(Vector3(41.0f, 1.0f, 1.0f));
		office1->GetComponent<Transform>()->SetScale(Vector3(9.0f, 5.0f, .0f));

		Pillar* pillar = new Pillar();
		AddGameObject(eLayerType::Structure_B, pillar);
		pillar->GetComponent<Transform>()->SetPosition(Vector3(42.0f, 1.1f, 0.6f));
		pillar->GetComponent<Transform>()->SetScale(Vector3(4.5f, 4.5f, .0f));

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