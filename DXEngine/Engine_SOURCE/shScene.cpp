#include "shScene.h"
#include "shObject.h"
#include "../DXEngine/shLobbyScene.h"
#include "../DXEngine/shDungeonScene.h"

namespace sh
{
	Player* Scene::mainPlayer;

	Scene::Scene()
	{
		mLayers.resize((int)sh::enums::eLayerType::End);
	}
	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer& layer : mLayers)
		{
			layer.LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer& layer : mLayers)
		{
			layer.Render();
		}
	}
	void Scene::Destroy()
	{
		for (Layer& layer : mLayers)
		{
			layer.Destory();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(eLayerType type, GameObject* gameObj)
	{
		mLayers[(int)type].AddGameObject(gameObj);
	}

	void Scene::LoadMainPlayer()
	{
		mainPlayer
			= object::newMainPlayer<Player>(Vector4(0.0f, 1.0f, object::zPlayer, 1.0f), L"SpriteAnimaionMaterial");

	}
	void Scene::PlayerResetTransform()
	{
		mainPlayer->GetComponent<Transform>()->SetPosition(0.0f,1.0f,object::zPlayer);
		mainPlayer->GetComponent<Rigidbody>()->SetGround(false);
	}
}
