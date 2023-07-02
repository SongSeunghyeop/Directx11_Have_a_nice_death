#include "shTree.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Tree::Tree()
	{

	}
	Tree::~Tree()
	{

	}
	void Tree::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"TreeMaterial"));

		GameObject::Initialize();
	}
	void Tree::Update()
	{
		GameObject::Update();
	}
	void Tree::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Tree::Render()
	{
		GameObject::Render();
	}
}