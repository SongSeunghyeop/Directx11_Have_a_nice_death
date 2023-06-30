#pragma once
#include <shScript.h>

namespace sh
{
	class PlayerController : public Script
	{
	public:
		virtual void Update() override;

		void Move();

	private:
		GameObject* target;
	};
}
