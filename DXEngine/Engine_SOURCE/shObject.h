#pragma once
#include "shGameObject.h"
#include "shTransform.h"
#include "shMeshRenderer.h"
#include "../DXEngine/shCamera.h"
#include "../DXEngine/shPlayer.h"
#include "../DXEngine/shFootHold.h"
#include "shLight.h"
#include "shScene.h"
#include "shSceneManager.h"

namespace sh::object
{
	const float zFront = - 2.0f; 
	const float zPlayer = -0.00001f;
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

	template <typename Light>
	static inline Light* newLight(Vector3 pos, eLightType type, float Radius = 1.5f, float Angle = 45.0f,Vector4 color = Vector4(169, 245, 225, 1.0f))
	{
		GameObject* light = new GameObject();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::Light, light);
		Transform* TR = light->GetComponent<Transform>();
		TR->SetPosition(pos);
		Light* lightComp = light->AddComponent<Light>();
		lightComp->SetType(type);
		lightComp->SetRadius(Radius);
		lightComp->SetAngle(Angle);
		lightComp->SetColor(color);
		light->Initialize();
		return lightComp;
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

	template <typename Player>
	static inline Player* newMainPlayer(Vector4 pos_size, std::wstring materialName)
	{
		Player* gameObj = new Player();

		MeshRenderer* mr = gameObj->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(materialName));

		if (mr->GetMaterial()->GetTexture())
		{
			Vector2 size = mr->GetTextureSize();
			gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * pos_size.w, size.y / 100.0f * pos_size.w, 1.0f);
		}
		// ¹ßÆÇ
		FootHold* footHold = new FootHold();
		footHold->Initialize();
		//
		gameObj->SetDrainage(Vector2(pos_size.w, pos_size.w));
		gameObj->GetComponent<Transform>()->SetPosition(pos_size.x, pos_size.y, pos_size.z);
		gameObj->setLayerType(eLayerType::Player);
		gameObj->SetMaterialName(materialName);
		gameObj->SetFootHold(footHold);
		gameObj->Initialize();
		footHold->SetPlayer(gameObj);
		//
		SceneManager::FindScene(L"LobbyScene")->AddGameObject(eLayerType::Player, gameObj);
		SceneManager::FindScene(L"DungeonScene")->AddGameObject(eLayerType::Player, gameObj);

		SceneManager::FindScene(L"LobbyScene")->AddGameObject(eLayerType::Player, footHold);
		SceneManager::FindScene(L"DungeonScene")->AddGameObject(eLayerType::Player, footHold);

		return gameObj;
	};

	template <typename T>
	static inline T* Instantiate(Vector4 pos_size, eLayerType type, std::wstring materialName)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObj);

		MeshRenderer* mr = gameObj->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(materialName));

		if (mr->GetMaterial()->GetTexture())
		{
			Vector2 size = mr->GetTextureSize();
			gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * pos_size.w, size.y / 100.0f * pos_size.w, 1.0f);
		}

		gameObj->SetDrainage(Vector2(pos_size.w, pos_size.w));
		gameObj->GetComponent<Transform>()->SetPosition(pos_size.x, pos_size.y, pos_size.z);
		gameObj->setLayerType(type);
		gameObj->SetMaterialName(materialName);
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

		if (mr->GetMaterial()->GetTexture())
		{
			Vector2 size = mr->GetTextureSize();
			gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * scale.x, size.y / 100.0f * scale.y, 1.0f);
		}

		gameObj->SetDrainage(scale);
		gameObj->GetComponent<Transform>()->SetPosition(pos.x, pos.y, pos.z);
		gameObj->setLayerType(type);
		gameObj->SetMaterialName(materialName);
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

		if (mr->GetMaterial()->GetTexture())
		{
			Vector2 size = mr->GetTextureSize();
			gameObj->GetComponent<Transform>()->SetScale(size.x / 100.0f * scale.x, size.y / 100.0f * scale.y, 1.0f);
		}
		gameObj->setLayerType(type);
		gameObj->SetDrainage(scale);
		gameObj->GetComponent<Transform>()->SetPosition(pos.x, pos.y, pos.z);
		gameObj->SetMaterialName(materialName);
		gameObj->Initialize();

		return gameObj;
	};

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(sh::GameObject::eState::Dead);
	}
}