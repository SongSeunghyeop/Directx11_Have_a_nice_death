#pragma once
#include "shScript.h"

namespace sh
{
	class CameraController : public Script
	{
	public:
		virtual void Update() override;

		void setTarget(GameObject *target)
		{
			Target = target;
		}
	private:
		GameObject *Target;
	};
}
