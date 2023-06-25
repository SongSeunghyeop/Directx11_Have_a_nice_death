#pragma once
#include "shGameObject.h"
#include "shPlayerController.h"

namespace sh
{
	class Player : public GameObject
	{
	public:
		Player();
		virtual ~Player();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Release();

	private:
		MeshRenderer* Player_MR;
		PlayerController* Player_CT;
	};
}

