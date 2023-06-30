#pragma once
#include "shGameObject.h"

namespace sh
{
	class Lobby : public GameObject
	{
	public:
		Lobby();
		~Lobby();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

