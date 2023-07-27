#pragma once
#include "shGameObject.h"

namespace sh
{
	class Floors : public GameObject
	{
	public:
		Floors();
		~Floors();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

