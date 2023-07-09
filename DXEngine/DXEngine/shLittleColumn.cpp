#include "shLittleColumn.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"

namespace sh
{
	LittleColumn::LittleColumn()
	{

	}
	LittleColumn::~LittleColumn()
	{

	}
	void LittleColumn::Initialize()
	{
		Transform* TR = this->GetComponent<Transform>();
		Vector3 pos = TR->GetPosition();

		enums::eLayerType type = this->getLayerType();

		GameObject* column1
			= object::Instantiate<GameObject>(Vector4(pos.x + 0.1f, pos.y - 2.3f, pos.z, 0.6f), type, L"ColumnMaterial");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector4(pos.x + 0.2f, pos.y - 4.6f, pos.z, 0.6f), type, L"ColumnMaterial");

		GameObject::Initialize();
	}
	void LittleColumn::Update()
	{
		GameObject::Update();
	}
	void LittleColumn::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void LittleColumn::Render()
	{
		GameObject::Render();
	}
}