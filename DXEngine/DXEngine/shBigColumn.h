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
		void setScale(float scale)
		{
			Scale = scale;
		}
		GameObject *getPillar()
		{
			return pillar;
		}
	private:
		float Scale;
		GameObject* pillar;
	};
}

