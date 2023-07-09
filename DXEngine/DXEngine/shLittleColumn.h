#pragma once
#include "shGameObject.h"

namespace sh
{
	class LittleColumn : public GameObject
	{
	public:
		LittleColumn();
		~LittleColumn();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

