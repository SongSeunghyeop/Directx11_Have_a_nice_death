#include "shPlayer.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shInput.h"
#include "shTime.h"
#include "shCameraController.h"

namespace sh
{
	Player::Player()
	{
		this->SetName(L"Player");
	}
	Player::~Player()
	{

	}
	void Player::Initialize()
	{
		this->AddComponent<Collider2D>();
		GameObject::Initialize();
	}
	void Player::Update()
	{
		float speed = 8.0f;

		Transform* tr = GetComponent<Transform>();
		Vector3 pos = tr->GetPosition(); // -14, 77

		if (Input::GetKey(eKeyCode::D))
		{
			if (pos.x > 90)
				speed = 0.0f;
			else
				speed = 8.0f;

			pos += Vector3(speed * Time::DeltaTime(), 0, 0);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			if (pos.x < -20)
				speed = 0.0f;
			else
				speed = 8.0f;

			pos += Vector3(-speed * Time::DeltaTime(), 0, 0);
		}
		else if (Input::GetKey(eKeyCode::W))
		{
			pos += Vector3(0, speed * Time::DeltaTime(), 0);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos += Vector3(0, -speed * Time::DeltaTime(), 0);
		}

		tr->SetPosition(pos);

		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();
	}
}