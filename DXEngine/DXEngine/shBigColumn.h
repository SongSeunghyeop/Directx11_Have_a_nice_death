#pragma once
#include "shGameObject.h"

namespace sh
{
	class BigColumn : public GameObject
	{
	public:
		BigColumn();
		~BigColumn();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

