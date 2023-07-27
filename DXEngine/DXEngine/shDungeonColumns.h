#pragma once
#include "shGameObject.h"

namespace sh
{
	class DungeonColumns : public GameObject
	{
	public:
		DungeonColumns();
		~DungeonColumns();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

