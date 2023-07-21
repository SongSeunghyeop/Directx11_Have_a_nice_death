#include "shD_Part1.h"
#include "shBigColumn.h"
#include "shObject.h"
#include "shSmallColumn.h"
#include "shGhostBox.h"

namespace sh
{
	D_Part1::D_Part1()
	{
		this->SetName(L"DungeonLobby");
	}
	D_Part1::~D_Part1()
	{

	}
	void D_Part1::Initialize()
	{
		GameObject* corne1
			= object::Instantiate<GameObject>(Vector4(16.9f, -5.19f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne1Material");
		GameObject* stoneLoad2
			= object::Instantiate<GameObject>(Vector3(16.85f, -6.3f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Structure_B, L"SquareStone2Material");

		SmallColumn* scolumn1
			= object::Instantiate<SmallColumn>(Vector3(19.5f, -1.5f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");
		SmallColumn* scolumn2
			= object::Instantiate<SmallColumn>(Vector3(22.0f, -1.5f, object::zBackGround), Vector2(0.45f, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");

		{
			GhostBox* ghostbox1
				= object::Instantiate<GhostBox>(Vector4(27.0f, -6.1f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox2
				= object::Instantiate<GhostBox>(Vector4(31.0f, -7.1f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox3
				= object::Instantiate<GhostBox>(Vector4(37.5f, -7.1f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox4
				= object::Instantiate<GhostBox>(Vector4(42.0f, -7.1f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox5
				= object::Instantiate<GhostBox>(Vector4(46.5f, -7.1f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox6
				= object::Instantiate<GhostBox>(Vector4(52.3, -6.2f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox7
				= object::Instantiate<GhostBox>(Vector4(57.5f, -2.9f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox8
				= object::Instantiate<GhostBox>(Vector4(61.0f, -2.9f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox9
				= object::Instantiate<GhostBox>(Vector4(65.6f, 1.0f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");

			GhostBox* ghostbox10
				= object::Instantiate<GhostBox>(Vector4(76.7f, -4.2f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox11
				= object::Instantiate<GhostBox>(Vector4(79.5f, -4.2f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox12
				= object::Instantiate<GhostBox>(Vector4(87.3f, -3.4f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox13
				= object::Instantiate<GhostBox>(Vector4(93.5f, -4.2f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"GhostBox1Material");

		}
		GameObject* CircleGround
			= object::Instantiate<GameObject>(Vector4(21.0, -9.5f, object::zBackGround, 1.0f), eLayerType::Ground_F, L"CircleGroundMaterial");
		GameObject* stoneLoad3
			= object::Instantiate<GameObject>(Vector4(19.2, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad4
			= object::Instantiate<GameObject>(Vector4(23.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad5
			= object::Instantiate<GameObject>(Vector4(27.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* corne2
			= object::Instantiate<GameObject>(Vector4(29.1f, -7.39f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne1Material");
		GameObject* stoneLoad6
			= object::Instantiate<GameObject>(Vector3(29.1f, -8.0f, object::zBackGround), Vector2(0.4, 0.17f), eLayerType::Structure_F, L"SquareStone2Material");
		GameObject* stoneLoad7
			= object::Instantiate<GameObject>(Vector4(31.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad8
			= object::Instantiate<GameObject>(Vector4(35.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad9
			= object::Instantiate<GameObject>(Vector4(39.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad10
			= object::Instantiate<GameObject>(Vector4(43.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad11
			= object::Instantiate<GameObject>(Vector4(47.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		
		{
			GameObject* stoneOnLoad1
				= object::Instantiate<GameObject>(Vector3(39.92f, -4.3f, object::zBackGround), Vector2(0.2f, 0.4f), eLayerType::Structure_B, L"SquareStone3Material");
			GameObject* stoneOnLoad2
				= object::Instantiate<GameObject>(Vector3(40.12f, -4.3f, object::zBackGround), Vector2(0.2f, 0.4f), eLayerType::Structure_B, L"SquareStone2Material");

			GameObject* column1
				= object::Instantiate<GameObject>(Vector3(40.0, -7.2f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_B, L"Column2Material");
		}
		
		{
			GameObject* column2
				= object::Instantiate<GameObject>(Vector3(45.0, -6.8f, object::zBackGround), Vector2(0.6f, 1.3f), eLayerType::Structure_B, L"Column2Material");
			GameObject* stoneOnLoad3
				= object::Instantiate<GameObject>(Vector3(46.5f, -4.1f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Structure_F, L"SquareStone1Material");
			GameObject* stoneOnLoad4
				= object::Instantiate<GameObject>(Vector3(49.5f, -4.1f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Structure_F, L"SquareStone1Material");
			GameObject* stoneOnLoad5
				= object::Instantiate<GameObject>(Vector3(46.5f, -4.5f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Structure_F, L"SquareStone4Material");
			GameObject* stoneOnLoad6
				= object::Instantiate<GameObject>(Vector3(49.5f, -4.5f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Structure_F, L"SquareStone4Material");
			GameObject* bridge1
				= object::Instantiate<GameObject>(Vector3(53.0f, -4.2f, object::zBackGround), Vector2(1.4f, 1.4f), eLayerType::Structure_B, L"BridgeMaterial");

			GameObject* column3
				= object::Instantiate<GameObject>(Vector3(50.0, -5.9f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_F, L"Column3Material");
			GameObject* column4
				= object::Instantiate<GameObject>(Vector3(51.0, -5.9f, object::zBackGround), Vector2(0.5f, 0.9f), eLayerType::Structure_F, L"Column3Material");
		}

		GameObject* stoneLoad12
			= object::Instantiate<GameObject>(Vector3(49.5, -8.5f, object::zBackGround), Vector2(0.4f, 0.17f), eLayerType::Structure_B, L"SquareStone3Material");
		GameObject* stoneLoad13
			= object::Instantiate<GameObject>(Vector3(52.2, -7.43f, object::zBackGround), Vector2(0.6f, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");

		{
			GameObject* groundFill1
				= object::Instantiate<GameObject>(Vector4(23.0f, -13.6f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill2
				= object::Instantiate<GameObject>(Vector4(35.2f, -14.6f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill3
				= object::Instantiate<GameObject>(Vector4(47.4f, -14.6f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill4
				= object::Instantiate<GameObject>(Vector4(55.5f, -13.6f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
		}

		GameObject::Initialize();
	}
	void D_Part1::Update()
	{
		GameObject::Update();
	}
	void D_Part1::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void D_Part1::Render()
	{
		GameObject::Render();
	}
}