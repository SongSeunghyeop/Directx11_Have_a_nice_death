#pragma once
#include "shGameObject.h"

namespace sh
{
	class D_Floors : public GameObject
	{
	public:
		D_Floors();
		~D_Floors();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

