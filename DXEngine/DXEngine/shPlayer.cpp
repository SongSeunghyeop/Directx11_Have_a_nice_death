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
		//this->AddComponent<Collider2D>();
		animator = this->AddComponent<Animator>();
		controller = this->AddComponent<PlayerController>();

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