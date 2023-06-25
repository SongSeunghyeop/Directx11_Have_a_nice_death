#pragma once
#include "shGameObject.h"

namespace sh
{
	class Lobby : public GameObject
	{
	public:
		Lobby();
		virtual ~Lobby();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Release();

	private:
		MeshRenderer *Lobby_MR;
	};
}

