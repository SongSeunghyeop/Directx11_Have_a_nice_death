#pragma once
#include "shGameObject.h"

namespace sh
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:

	};
}