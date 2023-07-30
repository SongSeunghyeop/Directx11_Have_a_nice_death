#include "shPlayerController.h"
#include "shTransform.h"
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
	}
	PlayerController::~PlayerController()
	{
	}
	void PlayerController::Initialize()
	{
		{
			moveKeys.push_back(eKeyCode::A);
			moveKeys.push_back(eKeyCode::D);
			moveKeys.push_back(eKeyCode::SPACE);
		}

		//크기를 줄이고 싶으면 transform->setScale()
		animator = GetOwner()->GetComponent<Animator>();
		//animator->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3, 3.f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Idle", 0.07f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Waiting", 0.1f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Run", 0.05f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Jump", 0.05f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack1", 0.06f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack2", 0.08f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack3", 0.08f);

		animator->PlayAnimation(L"TextureIdle", true);

		animator->CompleteEvent(L"TextureIdle") = std::bind(&PlayerController::Waiting, this);
		animator->CompleteEvent(L"TextureWaiting") = std::bind(&PlayerController::IdleMotion, this);
		animator->CompleteEvent(L"TextureAttack1") = std::bind(&PlayerController::Attack2Motion, this);
		animator->CompleteEvent(L"TextureAttack2") = std::bind(&PlayerController::Attack3Motion, this);
		animator->CompleteEvent(L"TextureAttack3") = std::bind(&PlayerController::IdleMotion, this);
		animator->CompleteEvent(L"TextureJump") = std::bind(&PlayerController::IdleMotion, this);

		meshRenderer = GetOwner()->GetComponent<MeshRenderer>();

		Collider2D *collider = GetOwner()->AddComponent<Collider2D>();

		moveState = eMoveState::Idle;
		animator->PlayAnimation(L"TextureIdle", true);
	}
	void PlayerController::Update()
	{
		switch (moveState)
		{
			case eMoveState::Idle:
			{
				Idle();
			} break;
			case eMoveState::Run:
			{
				Run();
			} break;
			case eMoveState::Attack:
			{
				Attack();
			} break;
		}
	}
	void PlayerController::Idle()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetScale(0.8, 0.8, 1.0f);

		for (int i = 0; i < 2; i++)
		{
			if (Input::GetKeyDown(moveKeys[i]) || Input::GetKey(moveKeys[i]))
			{
				moveState = eMoveState::Run;
				animator->PlayAnimation(L"TextureRun", true);
			}
		}
			if (Input::GetKeyDown(moveKeys[2]))
			{
				moveState = eMoveState::Attack;
				animator->PlayAnimation(L"TextureAttack1", true);
			}
	}
	void PlayerController::Attack()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetScale(2.5, 2.5, 1.0f);
	}
	void PlayerController::Run()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetScale(0.8, 0.8, 1.0f);

		if ((!Input::GetKeyDown(eKeyCode::A)) && (!Input::GetKey(eKeyCode::A))&&
			(!Input::GetKeyDown(eKeyCode::D)) && (!Input::GetKey(eKeyCode::D)))
		{
			moveState = eMoveState::Idle;
			IdleMotion();
		}

		Vector3 pos = tr->GetPosition();

		if (Input::GetKeyDown(eKeyCode::D) || Input::GetKey(eKeyCode::D))
		{
			Looking_Right();
		}
		if (Input::GetKeyDown(eKeyCode::A) || Input::GetKey(eKeyCode::A))
		{
			Looking_Left();
		}

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 15.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 15.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 15.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 15.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		tr->SetPosition(pos);
	}
	void PlayerController::OnCollisionEnter(Collider2D* other)
	{
		int a = 0;
	}
	void PlayerController::OnCollisionStay(Collider2D* other)
	{
		int c = 0;
	}
	void PlayerController::OnCollisionExit(Collider2D* other)
	{
		int b = 0;
	}

	void PlayerController::Waiting()
	{
		animator->PlayAnimation(L"TextureWaiting", true);
	}
	void PlayerController::IdleMotion()
	{
		moveState = eMoveState::Idle;
		animator->PlayAnimation(L"TextureIdle", true);
	}
	void PlayerController::Attack2Motion()
	{
		animator->PlayAnimation(L"TextureAttack2", true);
	}
	void PlayerController::Attack3Motion()
	{
		animator->PlayAnimation(L"TextureAttack3", true);
	}
}
