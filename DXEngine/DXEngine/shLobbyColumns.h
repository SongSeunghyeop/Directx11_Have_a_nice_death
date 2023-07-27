#pragma once
#include "shGameObject.h"

namespace sh
{
	class LobbyColumns : public GameObject
	{
	public:
		LobbyColumns();
		~LobbyColumns();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

