#include "shPlayer.h"
#include "shGameObject.h"
#include "shTime.h"
#include "shInput.h"
#include "shAnimator.h"
#include "shResources.h"
#include "shCollider2D.h"
#include "shSceneManager.h"
#include "shLight.h"

#define keyLEFT 0
#define keyRIGHT 1
#define keyE 2
#define keySHIFT 3
#define keySPACE 4

namespace sh
{
	FootHold* Player::foothold;
	Player::Player()
	{
		Direction_Right = 1;
		Direction_Left = 0;

	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		//this->AddComponent<Collider2D>();
		animator = this->AddComponent<Animator>();
		playerRG = this->AddComponent<Rigidbody>();
		Collider2D* collider = this->AddComponent<Collider2D>();
		playerTR = this->GetComponent<Transform>();

		Light* lightComp = this->AddComponent<Light>();
		lightComp->SetType(eLightType::Point);
		lightComp->SetColor(Vector4(169, 245, 225, 1.0f));
		lightComp->SetRadius(1.5f);

		runSpeed = 13.0f;

		Prev_pos = playerTR->GetPosition();

		this->GetComponent<Collider2D>()->SetColliderName(L"PlayerCollider");
		this->GetComponent<Collider2D>()->SetCenter(Vector2(0.0f, -0.8f));
		this->GetComponent<Collider2D>()->SetSize(Vector2(0.5f, 0.5f));


		{
			moveKeys.push_back(eKeyCode::A);
			moveKeys.push_back(eKeyCode::D);
			moveKeys.push_back(eKeyCode::E);
			moveKeys.push_back(eKeyCode::LEFT_SHIFT);
			moveKeys.push_back(eKeyCode::SPACE);
		}

		//크기를 줄이고 싶으면 transform->setScale()

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
		animator->SetAnimations(L"..\\Resources\\Texture\\Jump", 0.1f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Falling", 0.08f);
		animator->SetAnimations(L"..\\Resources\\Texture\\Dash", 0.05f);
		animator->CreateAnimations();

		{
			animator->CompleteEvent(L"IdleIdle1R") = std::bind(&Player::Idle2Motion, this);
			animator->CompleteEvent(L"IdleIdle2R") = std::bind(&Player::Idle3Motion, this);
			animator->CompleteEvent(L"IdleIdle3R") = std::bind(&Player::Idle4Motion, this);
			animator->CompleteEvent(L"IdleIdle4R") = std::bind(&Player::WaitingMotion, this);

			animator->CompleteEvent(L"IdleIdle1L") = std::bind(&Player::Idle2Motion, this);
			animator->CompleteEvent(L"IdleIdle2L") = std::bind(&Player::Idle3Motion, this);
			animator->CompleteEvent(L"IdleIdle3L") = std::bind(&Player::Idle4Motion, this);
			animator->CompleteEvent(L"IdleIdle4L") = std::bind(&Player::WaitingMotion, this);

			animator->CompleteEvent(L"AttackAttack1R") = std::bind(&Player::Attack2Motion, this);
			animator->CompleteEvent(L"AttackAttack2R") = std::bind(&Player::Attack3Motion, this);
			animator->CompleteEvent(L"AttackAttack3R") = std::bind(&Player::Attack4Motion, this);
			animator->CompleteEvent(L"AttackAttack4R") = std::bind(&Player::Idle1Motion, this);

			animator->CompleteEvent(L"AttackAttack1L") = std::bind(&Player::Attack2Motion, this);
			animator->CompleteEvent(L"AttackAttack2L") = std::bind(&Player::Attack3Motion, this);
			animator->CompleteEvent(L"AttackAttack3L") = std::bind(&Player::Attack4Motion, this);
			animator->CompleteEvent(L"AttackAttack4L") = std::bind(&Player::Idle1Motion, this);

			animator->CompleteEvent(L"TextureWaitingR") = std::bind(&Player::Idle1Motion, this);
			animator->CompleteEvent(L"TextureWaitingL") = std::bind(&Player::Idle1Motion, this);
		}

		meshRenderer = this->GetComponent<MeshRenderer>();

		activeState = eMoveState::Idle;
		animator->PlayAnimation(L"IdleIdle1R", true);
		playerTR->SetScale(3.0f, 3.0f, 1.0f);

	//	foothold->GetComponent<Transform>()->SetParent(this->GetComponent<Transform>());
	}
	void Player::Update()
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

		switch (activeState)
		{
		case eMoveState::Idle:
		{
			Transforming_moveState(eMoveState::Idle);
		}
		break;
		case eMoveState::Run:
		{
			Transforming_moveState(eMoveState::Run);
		}
		break;
		case eMoveState::Attack:
		{
			Transforming_moveState(eMoveState::Attack);
		}
		break;
		case eMoveState::Jump:
		{
			Transforming_moveState(eMoveState::Jump);
		}
		break;
		case eMoveState::RunJump:
		{
			Transforming_moveState(eMoveState::RunJump);
		}
		break;
		case eMoveState::Fall:
		{
			Transforming_moveState(eMoveState::Fall);
		}
		break;
		case eMoveState::Dash:
		{
			Transforming_moveState(eMoveState::Dash);
		}
		break;
		}

		GameObject::Update();

	}
	void Player::LateUpdate()
	{
		Vector3 FootHoldPos;
		FootHoldPos.x = playerTR->GetPosition().x;

		FootHoldPos.y = playerTR->GetPosition().y - 1.4f;
		FootHoldPos.z = playerTR->GetPosition().z;

		foothold->GetComponent<Transform>()->SetPosition(FootHoldPos);

		GameObject::LateUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();
	}
	void Player::Idle()
	{
		if (Input::GetKeyDown(eKeyCode::A) || Input::GetKeyDown(eKeyCode::D)) // key A
		{
			Transforming_moveState(eMoveState::Run);
		}
		else if (Input::GetKeyDown(eKeyCode::E)) // E
		{
			Transforming_moveState(eMoveState::Attack);
		}
		else if (Input::GetKeyDown(eKeyCode::SPACE)) // E
		{
			if (playerRG->GetState() == true) //2단 점프 불가
			{
				Transforming_moveState(eMoveState::Jump);
			}
		}
		else if (Input::GetKeyDown(eKeyCode::LEFT_SHIFT)) // E
		{
			Transforming_moveState(eMoveState::Dash);
		}
	}
	void Player::Attack()
	{
		if (Input::GetKey(moveKeys[0]) || Input::GetKey(moveKeys[1])) // key A
		{
			Transforming_moveState(eMoveState::Run);
		}
	}
	void Player::Jump()
	{
		jumped = true;
		Vector3 pos = playerTR->GetPosition();

		if (playerTR->GetPosition().y - Prev_pos.y < 4.0f)
			playerRG->AddForce(Vector3(0.0f, 30000.0f * Time::DeltaTime(), 0.0f));
		else
			Transforming_moveState(eMoveState::Fall);
	}
	void Player::Fall()
	{
		jumped = false;

		if (playerRG->GetState() == true)
		{
			if (Input::GetKey(moveKeys[0]) || Input::GetKey(moveKeys[1])) // key A
				Transforming_moveState(eMoveState::Run);
			else
				Transforming_moveState(eMoveState::Idle);
		}
	}

	void Player::Dash()
	{
		DashTime += Time::DeltaTime();

		Vector3 pos = playerTR->GetPosition();

		if (Direction_Right)
			playerTR->SetPosition(pos.x + 60.0f * Time::DeltaTime(), pos.y, pos.z);
		if (Direction_Left)
			playerTR->SetPosition(pos.x - 60.0f * Time::DeltaTime(), pos.y, pos.z);

		if (DashTime > 0.1f)
		{
			if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::D)) // key A
				Transforming_moveState(eMoveState::Run);
			else
				Transforming_moveState(eMoveState::Idle);

			DashTime = 0;
		}
	}

	void Player::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
		
		}
	}

	void Player::OnCollisionStay(Collider2D* other)
	{
	
	}

	void Player::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			runSpeed = 13.0f;
		}
	}

	void Player::Run()
	{
		if ((!Input::GetKeyDown(eKeyCode::A)) && (!Input::GetKey(eKeyCode::A)) &&
			(!Input::GetKeyDown(eKeyCode::D)) && (!Input::GetKey(eKeyCode::D)))
		{
			if (playerRG->GetState() == false)
				Transforming_moveState(eMoveState::Fall);
			else
				Transforming_moveState(eMoveState::Idle);
		}
		else if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			Transforming_moveState(eMoveState::RunJump);
		}
		else if (Input::GetKeyDown(eKeyCode::LEFT_SHIFT))
		{
			Transforming_moveState(eMoveState::Dash);
		}

		Vector3 pos = playerTR->GetPosition();

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= runSpeed * Time::DeltaTime();
			playerTR->SetPosition(pos);

		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += runSpeed * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}
		playerTR->SetPosition(pos);
	}
	void Player::RunJump()
	{
		jumped = true;
		Vector3 pos = playerTR->GetPosition();

		if (playerTR->GetPosition().y - Prev_pos.y < 4.0f)
		{
			if (Direction_Right)
				playerRG->AddForce(Vector3(100.0f, 550.0f, 0.0f));
			else if (Direction_Left)
				playerRG->AddForce(Vector3(-100.0f, 550.0f, 0.0f));
		}
		else
			Transforming_moveState(eMoveState::Fall);
	}

	void Player::WaitingMotion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"TextureWaitingR", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"TextureWaitingL", true);
	}

	void Player::Idle1Motion()
	{
		activeState = eMoveState::Idle;

		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle1R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle1L", true);
	}

	void Player::Idle2Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle2R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle2L", true);
	}

	void Player::Idle3Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle3R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle3L", true);
	}

	void Player::Idle4Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"IdleIdle4R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"IdleIdle4L", true);
	}
	void Player::RunMotion()
	{
		if (Direction_Right)
		{
			animator->PlayAnimation(L"TextureRunR", true);
		}
		else if (Direction_Left)
		{
			animator->PlayAnimation(L"TextureRunL", true);
		}
	}

	void Player::DashMotion()
	{
		if (Direction_Right)
		{
			animator->PlayAnimation(L"TextureDashR", true);
		}
		else if (Direction_Left)
		{
			animator->PlayAnimation(L"TextureDashL", true);
		}
	}
	void Player::JumpMotion()
	{
		if (Direction_Right)
		{
			animator->PlayAnimation(L"TextureJumpR", true);
		}
		else if (Direction_Left)
		{
			animator->PlayAnimation(L"TextureJumpL", true);
		}
	}
	void Player::FallMotion()
	{
		if (Direction_Right)
		{
			animator->PlayAnimation(L"TextureFallingR", true);
		}
		else if (Direction_Left)
		{
			animator->PlayAnimation(L"TextureFallingL", true);
		}
	}
	void Player::Attack1Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack1R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack1L", true);
	}
	void Player::Attack2Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack2R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack2L", true);
	}
	void Player::Attack3Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack3R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack3L", true);
	}
	void Player::Attack4Motion()
	{
		if (Direction_Right)
			animator->PlayAnimation(L"AttackAttack4R", true);
		else if (Direction_Left)
			animator->PlayAnimation(L"AttackAttack4L", true);
	}
}
