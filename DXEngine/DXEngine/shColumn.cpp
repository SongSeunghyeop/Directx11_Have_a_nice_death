#include "shColumn.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Column::Column()
	{

	}
	Column::~Column()
	{

	}
	void Column::Initialize()
	{
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"ColumnMaterial"));
		this->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.5f, .0f));

		GameObject::Initialize();
	}
	void Column::Update()
	{
		GameObject::Update();
	}
	void Column::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Column::Render()
	{
		GameObject::Render();
	}
}