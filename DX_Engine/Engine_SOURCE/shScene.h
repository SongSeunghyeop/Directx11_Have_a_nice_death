#pragma once
#include "shEntity.h"
#include "shLayer.h"

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
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(eLayerType type, GameObject* gameObj);

	private:
		std::vector<Layer> mLayers;
	};
}
