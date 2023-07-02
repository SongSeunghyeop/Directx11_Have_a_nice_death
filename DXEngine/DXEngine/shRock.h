#pragma once
#include "shGameObject.h"

namespace sh
{
	class Rock : public GameObject
	{
	public:
		Rock();
		~Rock();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

