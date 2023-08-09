#include "shPlayerController.h"
#include "shGameObject.h"
#include "shTime.h"
#include "shInput.h"
#include "shAnimator.h"
#include "shResources.h"
#include "shCollider2D.h"

namespace sh
{
	PlayerController::PlayerController()
	{
		Direction_Right = 1;
		Direction_Left = 0;

	}
	PlayerController::~PlayerController()
	{
	}
	void PlayerController::Initialize()
	{
		playerTR = GetOwner()->GetComponent<Transform>();

		this->GetOwner()->GetComponent<Collider2D>()->SetCenter(Vector2(0.0f, -0.8f));
		this->GetOwner()->GetComponent<Collider2D>()->SetSize(Vector2(0.5f, 0.5f));

		{
			moveKeys.push_back(eKeyCode::A);
			moveKeys.push_back(eKeyCode::D);
			moveKeys.push_back(eKeyCode::E);
			moveKeys.push_back(eKeyCode::LEFT_SHIFT);
		}

		playerRG = GetOwner()->GetComponent<Rigidbody>();

		//크기를 줄이고 싶으면 transform->setScale()
		animator = GetOwner()->GetComponent<Animator>();

		animator->SetAnimations(L"..\\Resources\\Texture\\Attack\\Attack1", 0.04f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Attack\\Attack2", 0.07f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Attack\\Attack3", 0.07f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Attack\\Attack4", 0.06f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Idle\\Idle1");
		animator->SetAnimations(L"..\\Resources\\Texture\\Idle\\Idle2");
		animator->SetAnimations(L"..\\Resources\\Texture\\Idle\\Idle3");
		animator->SetAnimations(L"..\\Resources\\Texture\\Idle\\Idle4");
		animator->SetAnimations(L"..\\Resources\\Texture\\Waiting");
		animator->SetAnimations(L"..\\Resources\\Texture\\Run");
		animator->SetAnimations(L"..\\Resources\\Texture\\Jump", 0.07f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Falling", 0.1f);
		animator->CreateAnimations();

		{
			animator->CompleteEvent(L"IdleIdle1R") = std::bind(&PlayerController::Idle2Motion, this);
			animator->CompleteEvent(L"IdleIdle2R") = std::bind(&PlayerController::Idle3Motion, this);
			animator->CompleteEvent(L"IdleIdle3R") = std::bind(&PlayerController::Idle4Motion, this);
			animator->CompleteEvent(L"IdleIdle4R") = std::bind(&PlayerController::Waiting, this);
			animator->CompleteEvent(L"IdleIdle1L") = std::bind(&PlayerController::Idle2Motion, this);
			animator->CompleteEvent(L"IdleIdle2L") = std::bind(&PlayerController::Idle3Motion, this);
			animator->CompleteEvent(L"IdleIdle3L") = std::bind(&PlayerController::Idle4Motion, this);
			animator->CompleteEvent(L"IdleIdle4L") = std::bind(&PlayerController::Waiting, this);
		}
		{
			animator->CompleteEvent(L"AttackAttack1R") = std::bind(&PlayerController::Attack2Motion, this);
			animator->CompleteEvent(L"AttackAttack2R") = std::bind(&PlayerController::Attack3Motion, this);
			animator->CompleteEvent(L"AttackAttack3R") = std::bind(&PlayerController::Attack4Motion, this);
			animator->CompleteEvent(L"AttackAttack4R") = std::bind(&PlayerController::Idle1Motion, this);
			animator->CompleteEvent(L"AttackAttack1L") = std::bind(&PlayerController::Attack2Motion, this);
			animator->CompleteEvent(L"AttackAttack2L") = std::bind(&PlayerController::Attack3Motion, this);
			animator->CompleteEvent(L"AttackAttack3L") = std::bind(&PlayerController::Attack4Motion, this);
			animator->CompleteEvent(L"AttackAttack4L") = std::bind(&PlayerController::Idle1Motion, this);
		}

		{
			animator->CompleteEvent(L"TextureJumpL") = std::bind(&PlayerController::Fall, this);
			animator->CompleteEvent(L"TextureJumpR") = std::bind(&PlayerController::Fall, this);

			animator->CompleteEvent(L"TextureWaitingR") = std::bind(&PlayerController::Idle1Motion, this);
			animator->CompleteEvent(L"TextureWaitingL") = std::bind(&PlayerController::Idle1Motion, this);
		}

		meshRenderer = GetOwner()->GetComponent<MeshRenderer>();
		{
			moveState = eMoveState::Idle;
			animator->PlayAnimation(L"IdleIdle1R", true);
			playerTR->SetScale(3.0f, 3.0f, 1.0f);
		}
	}
	void PlayerController::Update()
	{
		//실시간 방향 체크
		if (Input::GetKeyDown(eKeyCode::D) || Input::GetKey(eKeyCode::D))
		{
			Looking_Right();
		}
		if (Input::GetKeyDown(eKeyCode::A) || Input::GetKey(eKeyCode::A))
		{
			Looking_Left();
		}

		switch (moveState)
		{
			case eMoveState::Idle:
			{
				Idle();
			} 
			break;
			case eMoveState::Run:
			{
				Run();
			} 
			break;
			case eMoveState::Attack:
			{
				Attack();
			} 
			break;
		}
	}
	void PlayerController::Idle()
	{
		{
			Vector3 pos = playerTR->GetPosition();
			playerTR->SetPosition(pos);
		}

		if (Input::GetKeyDown(moveKeys[0])) // key A
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunL", true);
		}
		else if (Input::GetKeyDown(moveKeys[1])) // key D
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunR", true);
		}
		else if (Input::GetKeyDown(moveKeys[2])) // key Space
		{
			moveState = eMoveState::Attack;
			Attack1Motion();
		}
		else if (Input::GetKeyDown(moveKeys[3])) // E
		{
			if (playerRG->GetState() == true) //2단 점프 불가
			{
				Jump();
			}
		}
	
	}
	void PlayerController::Attack()
	{
		if (Input::GetKey(moveKeys[0])) // key A
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunL", true);
		}
		if (Input::GetKey(moveKeys[1])) // key D
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunR", true);
		}
	}
	void PlayerController::Jump()
	{
		jumped = true;
		Vector3 pos = playerTR->GetPosition();

		JumpPos = 3000.0f;

		if (Direction_Right)
			animator->PlayAnimation(L"TextureJumpR", true);
		else if (Direction_Left) 
			animator->PlayAnimation(L"TextureJumpL", true);
		
		if(moveState == eMoveState::Run)
			playerRG->AddForce(Vector3(0, JumpPos, 0));
		else
			playerRG->AddForce(Vector3(0, JumpPos, 0));
	}
	void PlayerController::Fall()
	{
		jumped = false;

		JumpPos = 0.0f;

		if (Direction_Right)
		{
				animator->PlayAnimation(L"TextureFallingR", true);
		}
		else if (Direction_Left)
		{
				animator->PlayAnimation(L"TextureFallingL", true);
		}
	}
	void PlayerController::Run()
	{
		if ((!Input::GetKeyDown(eKeyCode::A)) && (!Input::GetKey(eKeyCode::A))&&
			(!Input::GetKeyDown(eKeyCode::D)) && (!Input::GetKey(eKeyCode::D)))
		{
			if (playerRG->GetState() == false)
				Fall();
			else
			Idle1Motion();
			
		}
		else if (Input::GetKeyDown(eKeyCode::LEFT_SHIFT))
		{
			Jump();
		}

		Vector3 pos = playerTR->GetPosition();

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 13.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 13.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}

		playerTR->SetPosition(pos);
	}

	void PlayerController::Waiting()
	{
		if(Direction_Right)
			animator->PlayAnimation(L"TextureWaitingR", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"TextureWaitingL", true);
	}

	void PlayerController::Idle1Motion()
	{
		moveState = eMoveState::Idle;

		if(Direction_Right)
			animator->PlayAnimation(L"IdleIdle1R", true);
		else if(Direction_Left)
			animator->PlayAnimation(L"IdleIdle1L", true);
	}

	void PlayerController::Idle2Motion()
	{
		moveState = eMoveState::Idle;

		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle2R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle2L", true);
	}

	void PlayerController::Idle3Motion()
	{
		moveState = eMoveState::Idle;
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle3R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle3L", true);
	}

	void PlayerController::Idle4Motion()
	{
		moveState = eMoveState::Idle;
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle4R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle4L", true);
	}
	void PlayerController::Attack1Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);

		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack1R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack1L", true);
	}
	void PlayerController::Attack2Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);

		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack2R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack2L", true);
	}
	void PlayerController::Attack3Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);
		
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack3R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack3L", true);
	}
	void PlayerController::Attack4Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack4R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack4L", true);
	}

	void PlayerController::OnCollisionEnter(Collider2D* other)
	{
			if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
			{
				if (jumped)
				{
					playerRG->SetGround(false);

					if (moveState == eMoveState::Run)
					{
						playerRG->SetGround(true);
						jumped = false;
					}
				}
				else
					playerRG->SetGround(true);
			}
	}
	void PlayerController::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Rope")
		{
			if (Input::GetKey(eKeyCode::W))
			{
				Vector3 pos = playerTR->GetPosition();

				pos.y += 30.0f * Time::DeltaTime();
				
				playerTR->SetPosition(pos);
			}
		}

		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			if(jumped)
				playerRG->SetGround(false);
			else
			playerRG->SetGround(true);

			float y1 = this->GetOwner()->GetComponent<Collider2D>()->GetPosition().y - this->GetOwner()->GetComponent<Collider2D>()->GetScale().y / 2;
			float y2 = other->GetOwner()->GetComponent<Collider2D>()->GetPosition().y + other->GetOwner()->GetComponent<Collider2D>()->GetScale().y / 2;

			if (y1 < y2 - 0.08f)
			{
				Vector3 pos = this->GetOwner()->GetComponent<Transform>()->GetPosition();
				pos.y += 10.0f * Time::DeltaTime();
				this->GetOwner()->GetComponent<Transform>()->SetPosition(pos);
			}
		}
	}
	void PlayerController::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			playerRG->SetGround(false);
		}
	}
}
