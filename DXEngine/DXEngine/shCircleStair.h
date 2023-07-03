#pragma once
#include "shGameObject.h"

namespace sh
{
	class CircleStair : public GameObject
	{
	public:
		CircleStair();
		~CircleStair();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

