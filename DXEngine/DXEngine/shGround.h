#pragma once
#include "shGameObject.h"

namespace sh
{
	class Ground : public GameObject
	{
	public:
		Ground();
		~Ground();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

