#include "shPlayer.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shInput.h"
#include "shTime.h"

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
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"PlayerMaterial"));
	
		GameObject::Initialize();
	}
	void Player::Update()
	{
		float speed = 3.0f;

		Transform* tr = GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos += Vector3(speed * Time::DeltaTime(), 0, 0);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos += Vector3(-speed * Time::DeltaTime(), 0, 0);
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