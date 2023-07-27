#include "shPlayer.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shInput.h"
#include "shTime.h"
#include "shCameraController.h"
#include "shLight.h"

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
		meshrenderer = this->GetComponent<MeshRenderer>();

		Light* lightComp = this->AddComponent<Light>();
		lightComp->SetType(eLightType::Point);
		lightComp->SetColor(Vector4(169, 245, 225, 1.0f));
		lightComp->SetRadius(1.5f);

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