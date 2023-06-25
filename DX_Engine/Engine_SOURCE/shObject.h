#pragma once
#include "shGameObject.h"
#include "shScene.h"
#include "shSceneManager.h"
#include "shTransform.h"

namespace sh::object
{
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);
		//gameObj->Initialize(); // Scene에서부터 Initiailze()를 이미 해줌
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Vector3 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->GameObject::GetComponent<Transform>()->SetPosition(pos);
		//gameObj->Initialize();
		return gameObj;
	}

	/*static void Destory(GameObject* obj)
	{
		obj->setState(GameObject::eState::Death);
	}*/
}