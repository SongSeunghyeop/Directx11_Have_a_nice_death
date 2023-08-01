#pragma once
#include "shGameObject.h"
#include "shAnimator.h"
namespace sh
{
	class Elevator_NPC : public GameObject
	{
	public:
		Elevator_NPC();
		~Elevator_NPC();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
		Animator* animator;

	};
}

