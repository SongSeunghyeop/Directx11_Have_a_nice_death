#pragma once
#include "shGameObject.h"

namespace sh
{
	class Plaza : public GameObject
	{
	public:
		Plaza();
		~Plaza();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

