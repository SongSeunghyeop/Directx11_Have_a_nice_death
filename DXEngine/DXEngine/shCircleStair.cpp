#include "shCircleStair.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	CircleStair::CircleStair()
	{

	}
	CircleStair::~CircleStair()
	{

	}
	void CircleStair::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"CircleStairMaterial"));

		GameObject::Initialize();
	}
	void CircleStair::Update()
	{
		GameObject::Update();
	}
	void CircleStair::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void CircleStair::Render()
	{
		GameObject::Render();
	}
}