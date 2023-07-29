#include "shBigColumn.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"

namespace sh
{
	BigColumn::BigColumn()
	{

	}
	BigColumn::~BigColumn()
	{

	}
	void BigColumn::Initialize()
	{
		Transform* TR = this->GetComponent<Transform>();
		Vector3 pos = TR->GetPosition();
		float scaleX = this->GetDrainage().x;
		float scaleY = this->GetDrainage().y;
		enums::eLayerType type = this->getLayerType();

		pillar
			= object::Instantiate<GameObject>(Vector3(pos.x + 0.1f, pos.y - scaleY * 3.8, pos.z),Vector2(scaleX, scaleY), type, L"ColumnMaterial");

		GameObject::Initialize();
	}
	void BigColumn::Update()
	{
		GameObject::Update();
	}
	void BigColumn::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BigColumn::Render()
	{
		GameObject::Render();
	}
}