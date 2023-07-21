#pragma once
#include "shGameObject.h"

namespace sh
{
	class D_Part2 : public GameObject
	{
	public:
		D_Part2();
		~D_Part2();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

