#pragma once
#include "shGameObject.h"

namespace sh
{
	class SmallColumn : public GameObject
	{
	public:
		SmallColumn();
		~SmallColumn();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

