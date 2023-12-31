#pragma once
#include "shEntity.h"
#include "shLayer.h"
#include "../DXEngine/shCamera.h"
#include "../DXEngine/shPlayer.h"

namespace sh
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(eLayerType type, GameObject* gameObj);

		template <typename T>
		std::vector<T*> FindObjectsOfType()
		{
			std::vector<T*> findObjs = {};
			for (Layer* layer : mLayers)
			{
				auto gameObjs = layer->GetGameObjects();
				for (GameObject* obj : gameObjs)
				{
					T* buff = dynamic_cast<T*>(obj);
					if (buff != nullptr)
						findObjs.push_back(buff);
				}
			}

			return findObjs;
		}
		Layer& GetLayer(eLayerType type) { return mLayers[(UINT)type]; }
		
		void SetActiveCamera(Camera* c)
		{
			activeCamera = c;
		}
		Camera* GetActiveCamera()
		{
			return activeCamera;
		}
		static void LoadMainPlayer();

		static Player* GetMainPlayer()
		{
			return mainPlayer;
		}

		static void PlayerResetTransform();

	private:
		std::vector<Layer> mLayers;
		Camera* activeCamera;

		static Player* mainPlayer;
	};
}
