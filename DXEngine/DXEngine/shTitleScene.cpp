#include "shTitleScene.h"
#include "shTransform.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shPlayer.h"
#include "shInput.h"
#include "shObject.h"

namespace sh
{
	TitleScene::TitleScene()
	{

	}
	TitleScene::~TitleScene()
	{

	}
	void TitleScene::Initialize()
	{
		GameObject* title = object::Instantiate<GameObject>(Vector4(0.0f, 0.0f, 9.3f, 1.0f), eLayerType::UI,L"TitleMaterial");
		Camera* camera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"MenuScene");
		}

		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render()
	{
	
	}
}