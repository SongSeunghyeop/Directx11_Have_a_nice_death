#include "shPillar.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Pillar::Pillar()
	{

	}
	Pillar::~Pillar()
	{

	}
	void Pillar::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"PillarMaterial"));

		GameObject::Initialize();
	}
	void Pillar::Update()
	{
		GameObject::Update();
	}
	void Pillar::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Pillar::Render()
	{
		GameObject::Render();
	}
}