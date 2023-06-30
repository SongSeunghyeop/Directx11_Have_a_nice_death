#pragma once
//#include "shScript.h"
#include <shScript.h>

namespace sh
{
	class CameraController : public Script
	{
	public:
		CameraController();
	
		virtual void Update() override;

		void SetTarget(GameObject* T)
		{
			target = T;
		}

	private:
		GameObject* target;
	};
}
