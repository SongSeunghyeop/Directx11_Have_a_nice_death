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
		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"LinkSprite", L"..\\Resources\\Texture\\linkSprites.png");

		animator = GetOwner()->GetComponent<Animator>();
		animator->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3);
		animator->PlayAnimation(L"Idle", true);
		animator->CompleteEvent(L"Idle") = std::bind(&PlayerController::Complete, this);
	}
	void PlayerController::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 12.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 12.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 12.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 12.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

	}
	void PlayerController::Complete()
	{
		int a = 0;
	}
}
