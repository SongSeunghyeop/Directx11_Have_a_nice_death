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