#pragma once
#include <shScript.h>
#include "shAnimator.h"
#include "shPlayer.h"
#include "shMeshRenderer.h"
#include "shInput.h"

namespace sh
{
	class PlayerController : public Script
	{
	public:
		enum class eMoveState
		{
			Run,
			Idle,
			Attack,
			End,
		};
		PlayerController();
		~PlayerController();

		virtual void Initialize() override;
		virtual void Update() override;

		void Waiting();
		void Idle1Motion();
		void Idle2Motion();
		void Idle3Motion();
		void Idle4Motion();
		void Attack1Motion();
		void Attack2Motion();
		void Attack3Motion();
		void Attack4Motion();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void Run();
		void Idle();
		void Attack();

		void Looking_Right()
		{
			meshRenderer->Fliping(1);
			Direction_Right = 1;
			Direction_Left = 0;
		}
		void Looking_Left()
		{
			meshRenderer->Fliping(-1);
			Direction_Right = 0;
			Direction_Left = 1;
		}

	private:
		bool Direction_Right;
		bool Direction_Left;

		eMoveState moveState;
		Animator* animator;
		MeshRenderer* meshRenderer;

		std::vector<eKeyCode> moveKeys;
		Transform* playerTR;

		float gravity = 10.0f;

	};
}