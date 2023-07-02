#include "shWall.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Wall::Wall()
	{

	}
	Wall::~Wall()
	{

	}
	void Wall::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"WallMaterial"));

		GameObject::Initialize();
	}
	void Wall::Update()
	{
		GameObject::Update();
	}
	void Wall::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Wall::Render()
	{
		GameObject::Render();
	}
}