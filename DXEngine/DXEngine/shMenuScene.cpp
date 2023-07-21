#include "shMenuScene.h"
#include "shTransform.h"
#include "shCamera.h"
#include "shSceneManager.h"
#include "shPlayer.h"
#include "shInput.h"
#include "shObject.h"

namespace sh
{
	MenuScene::MenuScene()
	{

	}
	MenuScene::~MenuScene()
	{

	}
	void MenuScene::Initialize()
	{
		GameObject* Menu = object::Instantiate<GameObject>(Vector4(0.0f, 0.0f, 9.1f, 1.0f), eLayerType::UI, L"MenuMaterial");
		Camera* camera = object::newCamera<Camera>(eLayerType::Camera, L"UI");
	}

	void MenuScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"LobbyScene");
		}

		Scene::Update();
	}

	void MenuScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void MenuScene::Render()
	{

	}
}