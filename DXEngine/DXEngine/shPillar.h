#pragma once
#include "shGameObject.h"

namespace sh
{
	class Pillar : public GameObject
	{
	public:
		Pillar();
		~Pillar();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
	};
}

