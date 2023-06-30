#pragma once
#include "shGameObject.h"

namespace sh
{
	class Title : public GameObject
	{
	public:
		Title();
		~Title();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

