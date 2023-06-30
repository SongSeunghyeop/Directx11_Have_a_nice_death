#pragma once
#include "shGameObject.h"

namespace sh
{
	class Office : public GameObject
	{
	public:
		Office();
		~Office();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

