#include "shDungeonColumns.h"
#include "shObject.h"
#include "shBigColumn.h"
#include "shSmallColumn.h"

namespace sh
{
	DungeonColumns::DungeonColumns()
	{
		this->SetName(L"DungeonColumns");
	}
	DungeonColumns::~DungeonColumns()
	{

	}
	void DungeonColumns::Initialize()
	{
		SmallColumn* scolumn1
			= object::Instantiate<SmallColumn>(Vector3(19.5f, -1.5f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_F, L"ColumnMaterial");
		SmallColumn* scolumn2
			= object::Instantiate<SmallColumn>(Vector3(22.5f, -1.5f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_F, L"ColumnMaterial");

		{
			GameObject* column2
				= object::Instantiate<GameObject>(Vector3(45.0, -6.8f, object::zBackGround), Vector2(0.6f, 1.3f), eLayerType::Structure_B, L"Column2Material");
			GameObject* column3
				= object::Instantiate<GameObject>(Vector3(50.0, -5.9f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_F, L"Column3Material");
			GameObject* column4
				= object::Instantiate<GameObject>(Vector3(51.0, -5.9f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_F, L"Column3Material");
		}

		GameObject* column1
			= object::Instantiate<GameObject>(Vector3(57.07, -3.2f, object::zBackGround), Vector2(0.4f, 0.7f), eLayerType::Structure_B, L"Column2Material");
		GameObject* column2
			= object::Instantiate<GameObject>(Vector3(67.5f, 0.8f, object::zBackGround), Vector2(0.5f, 1.0f), eLayerType::Structure_B, L"Column2Material");
		GameObject* column3
			= object::Instantiate<GameObject>(Vector3(71.5f, 0.8f, object::zBackGround), Vector2(0.5f, 1.0f), eLayerType::Structure_B, L"Column2Material");

	
		GameObject::Initialize();
	}
	void DungeonColumns::Update()
	{
		GameObject::Update();
	}
	void DungeonColumns::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void DungeonColumns::Render()
	{
		GameObject::Render();
	}
}