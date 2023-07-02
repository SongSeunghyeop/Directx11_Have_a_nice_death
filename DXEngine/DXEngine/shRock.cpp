#include "shRock.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Rock::Rock()
	{

	}
	Rock::~Rock()
	{

	}
	void Rock::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"BigRockMaterial"));

		GameObject::Initialize();
	}
	void Rock::Update()
	{
		GameObject::Update();
	}
	void Rock::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Rock::Render()
	{
		GameObject::Render();
	}
}