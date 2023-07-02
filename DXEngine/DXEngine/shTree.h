#pragma once
#include "shGameObject.h"

namespace sh
{
	class Tree : public GameObject
	{
	public:
		Tree();
		~Tree();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

