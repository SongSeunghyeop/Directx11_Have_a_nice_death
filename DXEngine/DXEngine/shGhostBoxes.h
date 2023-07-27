#pragma once
#include "shGameObject.h"

namespace sh
{
	class GhostBoxes : public GameObject
	{
	public:
		GhostBoxes();
		~GhostBoxes();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

