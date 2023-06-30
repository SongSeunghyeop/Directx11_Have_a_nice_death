#include "shPlayer.h"
#include "shMeshRenderer.h"
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
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"PlayerMaterial"));
		this->GetComponent<Transform>()->SetScale(Vector3(0.6f, 0.6f, 0.6f));

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
}