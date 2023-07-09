#pragma once
#include "shGameObject.h"
#include "shScene.h"
#include "shSceneManager.h"
#include "shTransform.h"
#include "shMeshRenderer.h"
#include "shCamera.h"

namespace sh::object
{
	const float zPlayer = -2.0f;
	const float zBackGround = 0.0f;

	template <typename Camera>
	static inline Camera* newCamera(eLayerType type, std::wstring cameratype)
	{
		Camera* camera = new Camera(cameratype);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		camera->Initialize();
		return camera;
	};

	template <typename T>
	static inline T* Instantiate(Vector4 pos_size, eLayerType type, std::wstring materialName)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);

		MeshRenderer* mr = gameObj->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(materialName));

		Vector2 size = mr->GetTextureSize();

		gameObj->setLayerType(type);
		gameObj->GetComponent<Transform>()->SetPosition(pos_size.x,pos_size.y, pos_size.z);
		gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * pos_size.w, size.y / 100.0f * pos_size.w, 1.0f);
		gameObj->Initialize();

		return gameObj;
	};

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(sh::GameObject::eState::Dead);
	}
}