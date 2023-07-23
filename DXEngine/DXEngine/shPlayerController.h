#pragma once
#include <shScript.h>
#include "shAnimator.h"
#include "shPlayer.h"
namespace sh
{
	class PlayerController : public Script
	{
	public:
		PlayerController();
		~PlayerController();

		virtual void Initialize() override;
		virtual void Update() override;

		void Complete();

		//virtual void OnCollisionEnter(Collider2D* other) override;
		//virtual void OnCollisionStay(Collider2D* other) override;
		//virtual void OnCollisionExit(Collider2D* other) override;

	private:
		Animator* animator;
	};
}