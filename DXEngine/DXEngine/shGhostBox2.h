#pragma once
#include "shGameObject.h"

namespace sh
{
	class GhostBox2 : public GameObject
	{
	public:
		GhostBox2();
		~GhostBox2();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

