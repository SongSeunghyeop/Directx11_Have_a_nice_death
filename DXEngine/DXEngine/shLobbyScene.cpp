#include "shLobbyScene.h"
#include "shTransform.h"
#include "shCameraController.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shObject.h"
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
		Lobby* lobby = object::Instantiate<Lobby>(Vector3(0, 0.7, 20), Vector3(16.4f, 8.3f, .0f), eLayerType::BackGround );
		Player* Death = object::Instantiate<Player>(Vector3(0.0f, 0.0f, 0.4f), Vector3(0.5f, 0.5f, .0f), eLayerType::Player);

		Column* Colume_f1 = object::Instantiate<Column>(Vector3(7.0f, 2.8f, 0.01f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);
		Column* Colume_f2 = object::Instantiate<Column>(Vector3(7.1f, -0.1f, 0.0f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);

		Column* Colume_b1 = object::Instantiate<Column>(Vector3(8.05f, 2.7f, 0.8f), Vector3(1.0f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_b2 = object::Instantiate<Column>(Vector3(8.1f, 1.3f, 0.79f), Vector3(1.0f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_b3 = object::Instantiate<Column>(Vector3(8.15f, -0.1f, 0.78f), Vector3(1.0f, 2.0f, .0f), eLayerType::Structure_B);

		Column* Colume_b4 = object::Instantiate<Column>(Vector3(16.15f, 2.7f, 0.8f), Vector3(0.7f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_b5 = object::Instantiate<Column>(Vector3(16.2f, 1.3f, 0.79f), Vector3(0.7f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_b6 = object::Instantiate<Column>(Vector3(16.25f, -0.1f, 0.78f), Vector3(0.7f, 2.0f, .0f), eLayerType::Structure_B);

		Column* Colume_f3 = object::Instantiate<Column>(Vector3(18.50f, 2.35f, 0.02f), Vector3(0.8f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_f4 = object::Instantiate<Column>(Vector3(18.53f, 0.95f, 0.01f), Vector3(0.8f, 2.0f, .0f), eLayerType::Structure_B);
		Column* Colume_f5 = object::Instantiate<Column>(Vector3(18.56f, -0.45f, 0.0f), Vector3(0.8f, 2.0f, .0f), eLayerType::Structure_B);

		Column* Colume_f6 = object::Instantiate<Column>(Vector3(27.9f, 2.8f, 0.01f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);
		Column* Colume_f7 = object::Instantiate<Column>(Vector3(28.0f, -0.1f, 0.0f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);

		Column* Colume_f8 = object::Instantiate<Column>(Vector3(36.9f, 2.8f, 0.01f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);
		Column* Colume_f9 = object::Instantiate<Column>(Vector3(37.0f, -0.1f, 0.0f), Vector3(1.8f, 4.0f, .0f), eLayerType::Structure_F);

		Ground* ground1 = object::Instantiate<Ground>(Vector3(9.6f, -1.0f, 0.6f), Vector3(16.0f, 0.7f, .0f), eLayerType::Structure_B);
		Ground* ground2 = object::Instantiate<Ground>(Vector3(21.0f, -1.0f, 0.7f), Vector3(16.0f, 0.7f, .0f), eLayerType::Structure_B);
		Ground* ground3 = object::Instantiate<Ground>(Vector3(34.5f, -1.0f, 0.7f), Vector3(16.0f, 0.7f, .0f), eLayerType::Structure_B);

		Tree* tree = object::Instantiate<Tree>(Vector3(16.7f, 0.6f, 0.5f), Vector3(3.0f, 3.0f, .0f), eLayerType::Structure_B);
		CircleStair* circlestair = object::Instantiate<CircleStair>(Vector3(22.0f, -0.8f, 0.6f), Vector3(2.5f, 0.5f, .0f), eLayerType::Structure_B);
		Wall* wall = object::Instantiate<Wall>(Vector3(32.0, 0.9f, 0.6f), Vector3(4.5f, 4.5f, .0f), eLayerType::Structure_B);
		Pillar* pillar = object::Instantiate<Pillar>(Vector3(42.0f, 1.1f, 0.6f), Vector3(4.5f, 4.5f, .0f), eLayerType::Structure_B);
		
		Office* office0 = object::Instantiate<Office>(Vector3(23.0f, 1.0f, 1.0f), Vector3(9.0f, 5.0f, .0f), eLayerType::Structure_B);
		Office* office1 = object::Instantiate<Office>(Vector3(41.0f, 1.0f, 1.0f), Vector3(9.0f, 5.0f, .0f), eLayerType::Structure_B);
	
		GameObject* BossChair = new GameObject();
		BossChair->SetName(L"BossChair");
		AddGameObject(eLayerType::Structure_B, BossChair);
		MeshRenderer* m1 = BossChair->AddComponent<MeshRenderer>();
		m1->SetMaterial(Resources::Find<Material>(L"BossChairMaterial"));
		BossChair->GetComponent<Transform>()->SetPosition(Vector3(-0.45f, 1.2f, 0.7f));
		BossChair->GetComponent<Transform>()->SetScale(Vector3(1.0f, 1.8f, .0f));
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