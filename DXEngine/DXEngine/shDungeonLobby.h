#pragma once
#include "shGameObject.h"

namespace sh
{
	class DungeonLobby : public GameObject
	{
	public:
		DungeonLobby();
		~DungeonLobby();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

