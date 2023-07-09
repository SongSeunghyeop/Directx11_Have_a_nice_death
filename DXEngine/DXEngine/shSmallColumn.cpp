#include "shSmallColumn.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"

namespace sh
{
	SmallColumn::SmallColumn()
	{

	}
	SmallColumn::~SmallColumn()
	{

	}
	void SmallColumn::Initialize()
	{
		Transform* TR = this->GetComponent<Transform>();
		Vector3 pos = TR->GetPosition();

		enums::eLayerType type = this->getLayerType();

		GameObject* column1
			= object::Instantiate<GameObject>(Vector4(pos.x + 0.1f, pos.y - 3.1f, pos.z, 0.8f), type, L"ColumnMaterial");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector4(pos.x + 0.2f, pos.y - 6.2f, pos.z, 0.8f), type, L"ColumnMaterial");

		GameObject::Initialize();
	}
	void SmallColumn::Update()
	{
		GameObject::Update();
	}
	void SmallColumn::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SmallColumn::Render()
	{
		GameObject::Render();
	}
}