#include "shTitle.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Title::Title()
	{

	}
	Title::~Title()
	{

	}
	void Title::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"TitleMaterial"));
		this->GetComponent<Transform>()->SetScale(Vector3(8.0f, 4.5f, 0.0f));

		GameObject::Initialize();
	}
	void Title::Update()
	{
		GameObject::Update();
	}
	void Title::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Title::Render()
	{
		GameObject::Render();
	}
}