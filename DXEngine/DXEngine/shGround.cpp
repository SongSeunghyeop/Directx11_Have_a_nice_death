#include "shGround.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Ground::Ground()
	{

	}
	Ground::~Ground()
	{

	}
	void Ground::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"GroundMaterial"));

		GameObject::Initialize();
	}
	void Ground::Update()
	{
		GameObject::Update();
	}
	void Ground::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Ground::Render()
	{
		GameObject::Render();
	}
}