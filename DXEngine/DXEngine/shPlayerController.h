#pragma once
#include <shScript.h>
#include "shAnimator.h"
#include "shPlayer.h"
#include "shMeshRenderer.h"
#include "shInput.h"
#include "shRigidBody.h"

namespace sh
{
	class PlayerController : public Script
	{
	public:
		enum class eMoveState
		{
			Prev,
			Run,
			Idle,
			Jump,
			RunJump,
			Fall,
			Attack,
			Dash,
			End,
		};

		PlayerController();
		~PlayerController();

		virtual void Initialize() override;
		virtual void Update() override;

		void WaitingMotion();
		void Idle1Motion();
		void Idle2Motion();
		void Idle3Motion();
		void Idle4Motion();
		void Attack1Motion();
		void Attack2Motion();
		void Attack3Motion();
		void Attack4Motion();
		void RunMotion();
		void JumpMotion();
		void FallMotion();

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void Run();
		void Idle();
		void Attack();
		void Jump();
		void RunJump();
		void Fall();
		void Dash();

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
		void Transforming_moveState(eMoveState m)
		{
			activeState = m;

			if (prevState != activeState)
			{
				Playing = 0;
				prevState = activeState;
			}

			if (Playing == 0)
				Playing = 1;

			switch (m)
			{
			case(eMoveState::Idle):
			{
				Idle();

				if (Playing == 1)
				{
					Idle1Motion();
					Playing = -1;
				}
			} break;
			case(eMoveState::Attack):
			{
				Attack();

				if (Playing == 1)
				{
					Attack1Motion();
					Playing = -1;
				}
			} break;
			case(eMoveState::Run):
			{
				Run();

				if (Playing == 1)
				{
					RunMotion();
					Playing = -1;
				}
			} break;
			case(eMoveState::Jump):
			{
				Jump();

				if (Playing == 1)
				{
					JumpMotion();
					Playing = -1;
				}
			} break;
			case(eMoveState::RunJump):
			{
				RunJump();

				if (Playing == 1)
				{
					JumpMotion();
					Playing = -1;
				}
			} break;
			case(eMoveState::Fall):
			{
				Fall();

				if (Playing == 1)
				{
					FallMotion();
					Playing = -1;
				}
			} break;
			case(eMoveState::Dash):
			{
				Dash();

				if (Playing == 1)
				{
					RunMotion();
					Playing = -1;
				}
			} break;
			}
		}
	private:
		bool Direction_Right;
		bool Direction_Left;

		Animator* animator;
		MeshRenderer* meshRenderer;

		std::vector<eKeyCode> moveKeys;

		Transform* playerTR;
		Rigidbody* playerRG;

		bool jumped = false;
		float DashTime = 0.0f;

		int Playing = 0;

		eMoveState activeState;
		eMoveState prevState = eMoveState::Prev;

		float ground_posY = 0.0f;
	};
}