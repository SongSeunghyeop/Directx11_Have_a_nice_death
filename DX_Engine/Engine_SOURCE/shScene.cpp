#include "shScene.h"

namespace sh
{
	Scene::Scene()
	{
		mLayers.resize((int)sh::enums::eLayerType::End);
	}
	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{
		for (Layer& layer : mLayers)
		{
			layer.Initialize();
		}
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

	void Scene::Release()
	{
		for (Layer& layer : mLayers)
		{
			layer.Release();
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
}
