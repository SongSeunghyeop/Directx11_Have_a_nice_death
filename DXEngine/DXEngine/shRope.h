#pragma once
#include "shGameObject.h"

namespace sh
{
	class Rope : public GameObject
	{
	public:
		Rope();
		~Rope();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

