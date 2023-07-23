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
		camera->Initialize();
		return camera;
	};

	template <typename Camera>
	static inline Camera* newCamera(eLayerType type, std::wstring cameratype, Vector3 pos)
	{
		Camera* camera = new Camera(cameratype);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, camera);
		camera->SetFilmingPos(pos);
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

	
		gameObj->setLayerType(type);
		Vector2 size = mr->GetTextureSize();
		gameObj->SetDrainage(Vector2(pos_size.w, pos_size.w));
		gameObj->GetComponent<Transform>()->SetPosition(pos_size.x, pos_size.y, pos_size.z);
		gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * pos_size.w, size.y / 100.0f * pos_size.w, 1.0f);
		gameObj->Initialize();

		return gameObj;
	};

	template <typename T>
	static inline T* Instantiate(Vector3 pos, Vector2 scale, eLayerType type, std::wstring materialName)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);

		MeshRenderer* mr = gameObj->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(materialName));

		gameObj->setLayerType(type);
		Vector2 size = mr->GetTextureSize();
		gameObj->SetDrainage(scale);
		gameObj->GetComponent<Transform>()->SetPosition(pos.x, pos.y, pos.z);
		gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * scale.x, size.y / 100.0f * scale.y, 1.0f);
		gameObj->Initialize();
		return gameObj;
	};

	template <typename T>
	static inline T* Instantiate(Vector3 pos, Vector2 scale, Vector2 point, eLayerType type, std::wstring materialName)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);

		MeshRenderer* mr = gameObj->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(materialName));
		mr->SetEnd(point);

		Vector2 size = mr->GetTextureSize();

		gameObj->setLayerType(type);
		gameObj->SetDrainage(scale);
		gameObj->GetComponent<Transform>()->SetPosition(pos.x, pos.y, pos.z);
		gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * scale.x, size.y / 100.0f * scale.y, 1.0f);
		gameObj->Initialize();

		return gameObj;
	};

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(sh::GameObject::eState::Dead);
	}
}