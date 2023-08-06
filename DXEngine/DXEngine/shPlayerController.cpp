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
		
		{
			moveKeys.push_back(eKeyCode::A);
			moveKeys.push_back(eKeyCode::D);
			moveKeys.push_back(eKeyCode::SPACE);
			moveKeys.push_back(eKeyCode::E);
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
		animator->SetAnimations(L"..\\Resources\\Texture\\Jump");
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
			//animator->CompleteEvent(L"TextureJumpL") = std::bind(&PlayerController::Idle1Motion, this);
			//animator->CompleteEvent(L"TextureJumpR") = std::bind(&PlayerController::Idle1Motion, this);
			animator->CompleteEvent(L"TextureWaitingR") = std::bind(&PlayerController::Idle1Motion, this);
			animator->CompleteEvent(L"TextureWaitingL") = std::bind(&PlayerController::Idle1Motion, this);
		}

		meshRenderer = GetOwner()->GetComponent<MeshRenderer>();

		GetOwner()->AddComponent<Collider2D>();

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
			case eMoveState::Jump:
			{
				Jump();
			}
			break;
		}
	}
	void PlayerController::Idle()
	{
		{
			JumpPos = 200.0f;
			Vector3 pos = playerTR->GetPosition();
			playerTR->SetPosition(pos);
		}

		if (Input::GetKeyDown(moveKeys[0])) // key A
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunL", true);
		}
		if (Input::GetKeyDown(moveKeys[1])) // key D
		{
			moveState = eMoveState::Run;
			animator->PlayAnimation(L"TextureRunR", true);
		}
		if (Input::GetKeyDown(moveKeys[2])) // key Space
		{
			moveState = eMoveState::Attack;
			Attack1Motion();
		}
		if (Input::GetKeyDown(moveKeys[3])) // E
		{
			moveState = eMoveState::Jump;
			playerRG->AddForce(Vector3(0.0f, JumpPos, 0.0f));
			Jump();
			//Attack1Motion();
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
		//moveState = eMoveState::Idle;
	}
	void PlayerController::Run()
	{
		if ((!Input::GetKeyDown(eKeyCode::A)) && (!Input::GetKey(eKeyCode::A))&&
			(!Input::GetKeyDown(eKeyCode::D)) && (!Input::GetKey(eKeyCode::D)))
		{
			moveState = eMoveState::Idle;
			Idle1Motion();
		}

		Vector3 pos = playerTR->GetPosition();

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 15.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 15.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 15.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 15.0f * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}

		playerTR->SetPosition(pos);
	}

	void PlayerController::Waiting()
	{
		if(Direction_Right)
			animator->PlayAnimation(L"TextureWaitingR", true);
		if (Direction_Left)
			animator->PlayAnimation(L"TextureWaitingL", true);
	}
	void PlayerController::Idle1Motion()
	{
		moveState = eMoveState::Idle;

		if(Direction_Right)
			animator->PlayAnimation(L"IdleIdle1R", true);
		if(Direction_Left)
			animator->PlayAnimation(L"IdleIdle1L", true);
	}

	void PlayerController::Idle2Motion()
	{
		moveState = eMoveState::Idle;

		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle2R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle2L", true);
	}

	void PlayerController::Idle3Motion()
	{
		moveState = eMoveState::Idle;
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle3R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle3L", true);
	}

	void PlayerController::Idle4Motion()
	{
		moveState = eMoveState::Idle;
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle4R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle4L", true);
	}
	void PlayerController::Attack1Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);

		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack1R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack1L", true);
	}
	void PlayerController::Attack2Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);

		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack2R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack2L", true);
	}
	void PlayerController::Attack3Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);
		
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack3R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack3L", true);
	}
	void PlayerController::Attack4Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		playerTR->SetPosition(pos);
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack4R", true);
		if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack4L", true);
	}

	void PlayerController::OnCollisionEnter(Collider2D* other)
	{
		if(moveState == eMoveState::Jump)
			playerRG->SetGround(false);
		else
			playerRG->SetGround(true);
	}
	void PlayerController::OnCollisionStay(Collider2D* other)
	{
		if (moveState == eMoveState::Jump)
			playerRG->SetGround(false);
		else
			playerRG->SetGround(true);
	}
	void PlayerController::OnCollisionExit(Collider2D* other)
	{
		playerRG->SetGround(false);
	}
}
