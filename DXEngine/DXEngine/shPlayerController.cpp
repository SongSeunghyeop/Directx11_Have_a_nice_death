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
		}

		//크기를 줄이고 싶으면 transform->setScale()
		animator = GetOwner()->GetComponent<Animator>();
		//animator->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3, 3.f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Idle", 0.07f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Waiting", 0.1f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Run", 0.05f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Jump", 0.05f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack1", 0.04f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack2", 0.06f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack3", 0.06f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Attack4", 0.06f);

		animator->PlayAnimation(L"TextureIdle", true);

		animator->CompleteEvent(L"TextureIdle") = std::bind(&PlayerController::Waiting, this);
		animator->CompleteEvent(L"TextureWaiting") = std::bind(&PlayerController::IdleMotion, this);
		animator->CompleteEvent(L"TextureAttack1") = std::bind(&PlayerController::Attack2Motion, this);
		animator->CompleteEvent(L"TextureAttack2") = std::bind(&PlayerController::Attack3Motion, this);
		animator->CompleteEvent(L"TextureAttack3") = std::bind(&PlayerController::Attack4Motion, this);
		animator->CompleteEvent(L"TextureAttack4") = std::bind(&PlayerController::IdleMotion, this);
		animator->CompleteEvent(L"TextureJump") = std::bind(&PlayerController::IdleMotion, this);

		meshRenderer = GetOwner()->GetComponent<MeshRenderer>();

		GetOwner()->AddComponent<Collider2D>();

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
		{
			Vector3 pos = playerTR->GetPosition();
			pos.y -= gravity * Time::DeltaTime();
			playerTR->SetPosition(pos);
		}

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
				Attack1Motion();
			}
	}
	void PlayerController::Attack()
	{

	}
	void PlayerController::Run()
	{
		if ((!Input::GetKeyDown(eKeyCode::A)) && (!Input::GetKey(eKeyCode::A))&&
			(!Input::GetKeyDown(eKeyCode::D)) && (!Input::GetKey(eKeyCode::D)))
		{
			moveState = eMoveState::Idle;
			IdleMotion();
		}

		Vector3 pos = playerTR->GetPosition();

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
	void PlayerController::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Test")
		{
	 		Collider2D* player = playerTR->GetOwner()->GetComponent<Collider2D>();
			int a = 0;
		}
			
			gravity = 0;
	}
	void PlayerController::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Test")
			int a = 0;

		gravity = 0;
	}
	void PlayerController::OnCollisionExit(Collider2D* other)
	{
		gravity = 10.0f;
	}

	void PlayerController::Waiting()
	{
		playerTR->SetScale(0.9, 0.9, 1.0f);
		animator->PlayAnimation(L"TextureWaiting", true);
	}
	void PlayerController::IdleMotion()
	{
		playerTR->SetScale(0.9, 0.9, 1.0f);
		moveState = eMoveState::Idle;
		animator->PlayAnimation(L"TextureIdle", true);
	}
	void PlayerController::Attack1Motion()
	{
		//playerTR->SetScale(2.8f,2.0f,1.0f);
		Vector3 pos = playerTR->GetPosition();
		//pos.x += 120.f * Time::DeltaTime();
		playerTR->SetPosition(pos);
		animator->PlayAnimation(L"TextureAttack1", true);
	}
	void PlayerController::Attack2Motion()
	{
		//playerTR->SetScale(2.0f, 2.0f, 1.0f);
		Vector3 pos = playerTR->GetPosition();
		//pos.x += 120.f * Time::DeltaTime();
		playerTR->SetPosition(pos);
		animator->PlayAnimation(L"TextureAttack2", true);
	}
	void PlayerController::Attack3Motion()
	{
		//playerTR->SetScale(2.0f, 2.0f, 1.0f);
		Vector3 pos = playerTR->GetPosition();
		//pos.x += 120.f * Time::DeltaTime();
		playerTR->SetPosition(pos);
		animator->PlayAnimation(L"TextureAttack3", true);
	}
	void PlayerController::Attack4Motion()
	{
		Vector3 pos = playerTR->GetPosition();
		//pos.x += 120.f * Time::DeltaTime();
		playerTR->SetPosition(pos);
		//playerTR->SetScale(3.2f, 3.2f, 1.0f);
		animator->PlayAnimation(L"TextureAttack4", true);
	}
}
