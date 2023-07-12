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
		float scale = this->GetDrainage().x;
		enums::eLayerType type = this->getLayerType();

		GameObject* Colume
			= object::Instantiate<GameObject>(Vector4(pos.x + 0.1f, pos.y - scale * 3.8, pos.z, scale), type, L"ColumnMaterial");

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