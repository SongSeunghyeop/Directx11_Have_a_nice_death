#pragma once
#include "shGameObject.h"

namespace sh
{
	class Wall : public GameObject
	{
	public:
		Wall();
		~Wall();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

