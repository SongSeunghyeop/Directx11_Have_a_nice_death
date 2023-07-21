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
		float scalex = this->GetDrainage().x;
		float scaley = this->GetDrainage().y;
		enums::eLayerType type = this->getLayerType();

		GameObject* column1
			= object::Instantiate<GameObject>(Vector3(pos.x + scalex * 0.1f, pos.y - scaley * 3.87, pos.z),Vector2(scalex, scaley), type, L"ColumnMaterial");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector3(pos.x + scalex * 0.2f, pos.y - 2 * scaley * 3.87, pos.z), Vector2(scalex, scaley), type, L"ColumnMaterial");

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