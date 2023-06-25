#include "shPlayer.h"
#include "shTransform.h"

namespace sh
{
	Player::Player()
	{

	}
	Player::~Player()
	{

	}
	void Player::Initialize()
	{
		Player_MR = this->AddComponent<MeshRenderer>();
		Player_MR->SetMaterial(Resources::Find<Material>(L"PlayerMaterial"));

		this->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -5.0f, 0.0f));
		this->GetComponent<Transform>()->SetScale(Vector3(0.8f, 0.8f, 0.0f));

		Player_CT = this->AddComponent<PlayerController>();

		GameObject::Initialize();
	}
	void Player::Update()
	{
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
	void Player::Release()
	{
		GameObject::Release();
	}
}