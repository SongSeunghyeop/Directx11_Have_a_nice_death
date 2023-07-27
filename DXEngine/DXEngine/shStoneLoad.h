#pragma once
#include "shGameObject.h"

namespace sh
{
	class StoneLoad : public GameObject
	{
	public:
		StoneLoad();
		~StoneLoad();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

