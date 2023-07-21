#pragma once
#include "shGameObject.h"

namespace sh
{
	class D_Part1 : public GameObject
	{
	public:
		D_Part1();
		~D_Part1();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

