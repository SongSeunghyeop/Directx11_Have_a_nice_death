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
		float scale = this->GetDrainage().x;
		enums::eLayerType type = this->getLayerType();

		GameObject* column1
			= object::Instantiate<GameObject>(Vector4(pos.x + scale * 0.12f, pos.y - scale * 3.87, pos.z, scale), type, L"ColumnMaterial");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector4(pos.x + scale * 0.24f, pos.y - 2 * scale * 3.87, pos.z, scale), type, L"ColumnMaterial");

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