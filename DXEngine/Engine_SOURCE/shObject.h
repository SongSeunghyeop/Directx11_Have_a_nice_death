#pragma once
#include "shGameObject.h"
#include "shScene.h"
#include "shSceneManager.h"
#include "shTransform.h"

namespace sh::object
{
	template <typename T>
	static inline T* Instantiate(Vector3 pos,Vector3 Scale, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);
		gameObj->GetComponent<Transform>()->SetPosition(pos);
		gameObj->GetComponent<Transform>()->SetScale(Scale);
		gameObj->Initialize();
		return gameObj;
	};

	//static void Destory(GameObject* obj)
	//{
	//	obj->setState(GameObject::eState::Death);
	//}
}