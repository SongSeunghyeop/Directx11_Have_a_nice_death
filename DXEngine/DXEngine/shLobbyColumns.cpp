#include "shLobbyColumns.h"
#include "shObject.h"
#include "shBigColumn.h"
#include "shSmallColumn.h"

namespace sh
{
	LobbyColumns::LobbyColumns()
	{
		this->SetName(L"LobbyColumns");
	}
	LobbyColumns::~LobbyColumns()
	{

	}
	void LobbyColumns::Initialize()
	{
		BigColumn* column1
			= object::Instantiate<BigColumn>(Vector4(14.0f, -1.4f, object::zPlayer, 0.8f), eLayerType::Structure_F, L"ColumnMaterial");
		SmallColumn* column2
			= object::Instantiate<SmallColumn>(Vector4(7.4f, 1.8f, object::zBackGround, 0.7f), eLayerType::Structure_B, L"ColumnMaterial");
		SmallColumn* column3
			= object::Instantiate<SmallColumn>(Vector4(15.0f, 2.0f, object::zBackGround, 0.8f), eLayerType::Structure_B, L"ColumnMaterial");
		
		SmallColumn* column4
			= object::Instantiate<SmallColumn>(Vector3(27.5f, 0.2f, object::zBackGround), Vector2(0.4f,0.6f), eLayerType::Structure_B, L"ColumnMaterial");
		SmallColumn* column5
			= object::Instantiate<SmallColumn>(Vector3(33.5f, 0.2f, object::zBackGround), Vector2(0.4f, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");
		SmallColumn* column6
			= object::Instantiate<SmallColumn>(Vector3(34.0f, -0.7f, object::zPlayer), Vector2(0.45f, 0.6f), eLayerType::Structure_F, L"ColumnMaterial");
		SmallColumn* column7
			= object::Instantiate<SmallColumn>(Vector3(36.0f, 0.2f, object::zBackGround), Vector2(0.4f, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");
		SmallColumn* column8
			= object::Instantiate<SmallColumn>(Vector3(42.0f, 0.2f, object::zBackGround), Vector2(0.4f, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");
		
		SmallColumn* column11
			= object::Instantiate<SmallColumn>(Vector3(43.5f, -0.8f, object::zPlayer), Vector2(0.45f, 0.6f), eLayerType::Structure_F, L"ColumnMaterial");
		BigColumn* column12
			= object::Instantiate<BigColumn>(Vector3(45.2f, -2.0f, object::zPlayer), Vector2(0.8f, 1.0f), eLayerType::Structure_F, L"ColumnMaterial");
		BigColumn* column13
			= object::Instantiate<BigColumn>(Vector3(63.0f, -2.0f, object::zPlayer), Vector2(0.8f, 1.0f), eLayerType::Structure_F, L"ColumnMaterial");

		GameObject::Initialize();
	}
	void LobbyColumns::Update()
	{
		GameObject::Update();
	}
	void LobbyColumns::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void LobbyColumns::Render()
	{
		GameObject::Render();
	}
}