#include "shPlayerController.h"
#include "shTransform.h"
#include "shGameObject.h"
#include "shTime.h"
#include "shInput.h"
#include "shAnimator.h"
#include "shResources.h"

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
		//크기를 줄이고 싶으면 transform->setScale()
		animator = GetOwner()->GetComponent<Animator>();
		//animator->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3, 3.f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Idle", 0.07f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Waiting", 0.1f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Run", 0.05f);
		animator->CreateAnimations(L"..\\Resources\\Texture\\Jump", 0.05f);

		animator->PlayAnimation(L"TextureIdle", true);

		animator->CompleteEvent(L"TextureIdle") = std::bind(&PlayerController::Waiting, this);
		animator->CompleteEvent(L"TextureWaiting") = std::bind(&PlayerController::IdleMotion, this);
		animator->CompleteEvent(L"TextureJump") = std::bind(&PlayerController::IdleMotion, this);

		meshRenderer = GetOwner()->GetComponent<MeshRenderer>();
	}
	void PlayerController::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetScale(0.7f, 0.7f, 1.0f);
		Vector3 pos = tr->GetPosition();

		if(animator->GetActiveAnimation() == animator->FindAnimation(L"TextureJump"))
			tr->SetScale(1.0f, 1.0f, 1.0f);

		if (Input::GetKeyDown(eKeyCode::D))
		{
			meshRenderer->Fliping(1);

			animator->PlayAnimation(L"TextureRun", true);
		}
		if (Input::GetKeyUp(eKeyCode::D))
		{
			meshRenderer->Fliping(1);

			animator->PlayAnimation(L"TextureIdle", true);
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			meshRenderer->Fliping(-1);

			animator->PlayAnimation(L"TextureRun", true);
		}
		if (Input::GetKeyUp(eKeyCode::A))
		{
			meshRenderer->Fliping(-1);
			animator->PlayAnimation(L"TextureIdle", true);
		}

		if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			animator->PlayAnimation(L"TextureJump", true);
		}
		if (Input::GetKey(eKeyCode::SPACE))
		{
			pos.y += 15.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else
		{
			if (pos.y > -3.6f)
			{
				pos.y -= 18.0f * Time::DeltaTime();
		    	tr->SetPosition(pos);
			}
		}

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 10.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 10.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 10.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 10.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
	void PlayerController::Waiting()
	{
		animator->PlayAnimation(L"TextureWaiting", true);
	}
	void PlayerController::IdleMotion()
	{
		animator->PlayAnimation(L"TextureIdle", true);
	}
}
