#pragma once
#include "shGameObject.h"

namespace sh
{
	class LightingLogo : public GameObject
	{
	public:
		LightingLogo();
		~LightingLogo();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

