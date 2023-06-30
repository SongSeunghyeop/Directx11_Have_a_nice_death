#pragma once
#include "shGameObject.h"

namespace sh
{
	class Column : public GameObject
	{
	public:
		Column();
		~Column();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

