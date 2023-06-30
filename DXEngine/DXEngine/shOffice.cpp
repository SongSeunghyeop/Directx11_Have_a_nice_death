#include "shOffice.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Office::Office()
	{

	}
	Office::~Office()
	{

	}
	void Office::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"OfficeMaterial"));
		this->GetComponent<Transform>()->SetScale(Vector3(12.0f, 7.0f, .0f));

		GameObject::Initialize();
	}
	void Office::Update()
	{
		GameObject::Update();
	}
	void Office::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Office::Render()
	{
		GameObject::Render();
	}
}