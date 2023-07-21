#include "shD_Part2.h"
#include "shBigColumn.h"
#include "shObject.h"
#include "shSmallColumn.h"

namespace sh
{
	D_Part2::D_Part2()
	{
		this->SetName(L"DungeonLobby");
	}
	D_Part2::~D_Part2()
	{

	}
	void D_Part2::Initialize()
	{
		GameObject* stoneLoad1
			= object::Instantiate<GameObject>(Vector3(55.0, -5.8f, object::zBackGround), Vector2(0.4f, 0.35f), eLayerType::Structure_B, L"SquareStone3Material");
		GameObject* corne1
			= object::Instantiate<GameObject>(Vector4(54.97, -4.2f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne2Material");
		GameObject* stoneLoad2
			= object::Instantiate<GameObject>(Vector4(56.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad3
			= object::Instantiate<GameObject>(Vector4(60.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Structure_B, L"SquareStone1Material");
		
		{
			GameObject* stoneOnLoad1
				= object::Instantiate<GameObject>(Vector3(57.0f, -1.3f, object::zBackGround), Vector2(0.15f, 0.25f), eLayerType::Structure_F, L"SquareStone3Material");
			GameObject* stoneOnLoad2
				= object::Instantiate<GameObject>(Vector3(57.15f, -1.3f, object::zBackGround), Vector2(0.15f, 0.25f), eLayerType::Structure_F, L"SquareStone2Material");
			GameObject* bridge1
				= object::Instantiate<GameObject>(Vector3(58.2f, -0.4f, object::zBackGround), Vector2(0.9f, 0.9f), eLayerType::Structure_B, L"BridgeMaterial");
			GameObject* column1
				= object::Instantiate<GameObject>(Vector3(57.07, -3.2f, object::zBackGround), Vector2(0.4f, 0.7f), eLayerType::Structure_B, L"Column2Material");
		}

		{
			GameObject* stoneOnLoad3
				= object::Instantiate<GameObject>(Vector3(67.5f, 2.6f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Structure_F, L"SquareStone1Material");
			GameObject* stoneOnLoad4
				= object::Instantiate<GameObject>(Vector3(67.5f, 2.1f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Structure_F, L"SquareStone4Material");
			GameObject* bridge2
				= object::Instantiate<GameObject>(Vector3(69.5f, 2.65f, object::zBackGround), Vector2(1.1f, 1.1f), eLayerType::Structure_B, L"BridgeMaterial");
			GameObject* stoneOnLoad5
				= object::Instantiate<GameObject>(Vector3(71.5f, 2.6f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Structure_F, L"SquareStone1Material");
			GameObject* stoneOnLoad6
				= object::Instantiate<GameObject>(Vector3(71.5f, 2.1f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Structure_F, L"SquareStone4Material");
			
			GameObject* column2
				= object::Instantiate<GameObject>(Vector3(67.5f, 0.8f, object::zBackGround), Vector2(0.5f, 1.0f), eLayerType::Structure_B, L"Column2Material");
			GameObject* column3
				= object::Instantiate<GameObject>(Vector3(71.5f, 0.8f, object::zBackGround), Vector2(0.5f, 1.0f), eLayerType::Structure_B, L"Column2Material");
		}

		GameObject* corne2
			= object::Instantiate<GameObject>(Vector4(62.84f, -0.36f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne2Material");
		GameObject* stoneLoad4
			= object::Instantiate<GameObject>(Vector4(62.85f, -2.0f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone3Material");
		GameObject* stoneLoad5
			= object::Instantiate<GameObject>(Vector4(64.7f, -0.4f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* stoneLoad6
			= object::Instantiate<GameObject>(Vector4(68.7f, -0.4f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* stoneLoad7
			= object::Instantiate<GameObject>(Vector4(72.7f, -0.4f, object::zBackGround, 0.4f), eLayerType::Structure_F, L"SquareStone1Material");
		GameObject* stoneLoad8
			= object::Instantiate<GameObject>(Vector3(74.7f, -3.55f, object::zBackGround),Vector2(0.4f, 0.7f), Vector2(1.0f, 1.0f), eLayerType::Structure_B, L"SquareStone2Material");
		GameObject* corne3
			= object::Instantiate<GameObject>(Vector4(74.73f, -0.38f, object::zBackGround, 0.7f), eLayerType::Corne, L"Corne1Material");
		
		{
			GameObject* bridge3
				= object::Instantiate<GameObject>(Vector3(76.0f, -0.25f, object::zBackGround), Vector2(1.0f, 1.0f), eLayerType::Structure_B, L"BridgeMaterial");
			GameObject* stoneOnLoad7
				= object::Instantiate<GameObject>(Vector3(77.5f, -0.33f, object::zBackGround), Vector2(0.15f,0.35f), Vector2(0.25f,0.8f), eLayerType::Structure_F, L"SquareStone1Material");
			GameObject* stoneOnLoad8
				= object::Instantiate<GameObject>(Vector3(77.5f, -0.4f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Structure_F, L"SquareStone4Material");
			GameObject* bridge4
				= object::Instantiate<GameObject>(Vector3(79.0f, -0.25f, object::zBackGround), Vector2(1.0f, 1.0f), eLayerType::Structure_B, L"BridgeMaterial");
		}

		GameObject* stoneLoad9
			= object::Instantiate<GameObject>(Vector3(78.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad10
			= object::Instantiate<GameObject>(Vector3(84.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad11
			= object::Instantiate<GameObject>(Vector3(90.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad12
			= object::Instantiate<GameObject>(Vector3(96.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");

		{
			GameObject* stoneLoad13
				= object::Instantiate<GameObject>(Vector3(88.0f, -5.1f, object::zBackGround), Vector2(0.8f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");
			GameObject* stoneLoad14
				= object::Instantiate<GameObject>(Vector3(88.14f, -4.7f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Structure_B, L"SquareStone1Material");
		}

		GameObject* stoneLoad15
			= object::Instantiate<GameObject>(Vector3(99.0f, -8.23f, object::zBackGround), Vector2(0.3f, 0.6f), eLayerType::Structure_B, L"SquareStone2Material");
		
		GameObject* stoneLoad16
			= object::Instantiate<GameObject>(Vector3(100.0f, -9.5f, object::zBackGround), Vector2(0.2f, 0.6f), Vector2(0.4f, 1.0f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad17
			= object::Instantiate<GameObject>(Vector3(109.0f, -9.5f, object::zBackGround), Vector2(0.5f, 0.6f), eLayerType::Structure_B, L"SquareStone1Material");
		GameObject* stoneLoad18
			= object::Instantiate<GameObject>(Vector3(104.0f, -10.0f, object::zBackGround), Vector2(0.7f, 0.2f), eLayerType::Structure_B, L"SquareStone1Material");

		GameObject* elevator
			= object::Instantiate<GameObject>(Vector4(109.0f, -7.4f, object::zBackGround, 1.0f), eLayerType::Structure_F, L"Elevator_Material");

		{
			GameObject* groundFill1
				= object::Instantiate<GameObject>(Vector4(61.0f, -10.4f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill2
				= object::Instantiate<GameObject>(Vector4(68.8f, -6.6f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill3
				= object::Instantiate<GameObject>(Vector4(81.0f, -11.8f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill4
				= object::Instantiate<GameObject>(Vector4(88.7f, -11.8f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill5
				= object::Instantiate<GameObject>(Vector4(93.1f, -11.8f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* groundFill6
				= object::Instantiate<GameObject>(Vector4(105.3f, -16.2f, object::zBackGround, 1.2f), eLayerType::Ground_Fill, L"GroundFillMaterial");
		}

		GameObject::Initialize();
	}
	void D_Part2::Update()
	{
		GameObject::Update();
	}
	void D_Part2::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void D_Part2::Render()
	{
		GameObject::Render();
	}
}