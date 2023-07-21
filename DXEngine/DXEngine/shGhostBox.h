#pragma once
#include "shGameObject.h"

namespace sh
{
	class GhostBox : public GameObject
	{
	public:
		GhostBox();
		~GhostBox();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

