#pragma once
#include "shGameObject.h"

namespace sh
{
	class StoneLoads : public GameObject
	{
	public:
		StoneLoads();
		~StoneLoads();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

