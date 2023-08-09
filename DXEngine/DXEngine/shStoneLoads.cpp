#include "shStoneLoads.h"
#include "shObject.h"
#include "shStoneLoad.h"

namespace sh
{
	StoneLoads::StoneLoads()
	{
		this->SetName(L"StoneLoads");
	}
	StoneLoads::~StoneLoads()
	{

	}
	void StoneLoads::Initialize()
	{
		StoneLoad* stoneLoad1
			= object::Instantiate<StoneLoad>(Vector4(15.0f, -5.2f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad2
			= object::Instantiate<StoneLoad>(Vector3(16.85f, -6.3f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Ground, L"SquareStone2Material");
		StoneLoad* stoneLoad3
			= object::Instantiate<StoneLoad>(Vector4(19.2, -7.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad4
			= object::Instantiate<StoneLoad>(Vector4(23.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad5
			= object::Instantiate<StoneLoad>(Vector4(27.2f, -7.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad6
			= object::Instantiate<StoneLoad>(Vector3(29.1f, -8.0f, object::zBackGround), Vector2(0.4, 0.17f), eLayerType::Ground, L"SquareStone2Material");
		StoneLoad* stoneLoad7
			= object::Instantiate<StoneLoad>(Vector4(31.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad8
			= object::Instantiate<StoneLoad>(Vector4(35.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad9
			= object::Instantiate<StoneLoad>(Vector4(39.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad10
			= object::Instantiate<StoneLoad>(Vector4(43.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad11
			= object::Instantiate<StoneLoad>(Vector4(47.0, -8.4f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		{
			GameObject* stoneOnLoad1
				= object::Instantiate<GameObject>(Vector3(39.92f, -4.3f, object::zBackGround), Vector2(0.2f, 0.4f), eLayerType::Ground, L"SquareStone3Material");
			GameObject* stoneOnLoad2
				= object::Instantiate<GameObject>(Vector3(40.12f, -4.3f, object::zBackGround), Vector2(0.2f, 0.4f), eLayerType::Ground, L"SquareStone2Material");
		}

		{
			GameObject* stoneOnLoad3
				= object::Instantiate<GameObject>(Vector3(46.5f, -4.1f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Ground, L"SquareStone1Material");
			GameObject* stoneOnLoad4
				= object::Instantiate<GameObject>(Vector3(49.5f, -4.1f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Ground, L"SquareStone1Material");
			GameObject* stoneOnLoad5
				= object::Instantiate<GameObject>(Vector3(46.5f, -4.5f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Ground, L"SquareStone4Material");
			GameObject* stoneOnLoad6
				= object::Instantiate<GameObject>(Vector3(49.5f, -4.5f, object::zBackGround), Vector2(0.4f, 0.25f), eLayerType::Ground, L"SquareStone4Material");

			GameObject* bridge1
				= object::Instantiate<GameObject>(Vector3(53.0f, -4.2f, object::zBackGround), Vector2(1.4f, 1.4f), eLayerType::Ground, L"BridgeMaterial");
		}

		StoneLoad* stoneLoad12
			= object::Instantiate<StoneLoad>(Vector3(49.5, -8.5f, object::zBackGround), Vector2(0.4f, 0.17f), eLayerType::Ground, L"SquareStone3Material");
		StoneLoad* stoneLoad13
			= object::Instantiate<StoneLoad>(Vector3(52.2f, -7.43f, object::zBackGround), Vector2(0.6f, 0.4f), eLayerType::Ground, L"SquareStone1Material");

		StoneLoad* stoneLoad14
			= object::Instantiate<StoneLoad>(Vector3(55.0f, -5.8f, object::zBackGround), Vector2(0.4f, 0.35f), eLayerType::Ground, L"SquareStone3Material");
		StoneLoad* stoneLoad15
			= object::Instantiate<StoneLoad>(Vector4(56.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		StoneLoad* stoneLoad16
			= object::Instantiate<StoneLoad>(Vector4(60.7f, -4.21f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone1Material");
		
		{
			GameObject* stoneOnLoad7
				= object::Instantiate<GameObject>(Vector3(57.0f, -1.3f, object::zBackGround), Vector2(0.15f, 0.25f), eLayerType::Ground, L"SquareStone3Material");
			GameObject* stoneOnLoad8
				= object::Instantiate<GameObject>(Vector3(57.15f, -1.3f, object::zBackGround), Vector2(0.15f, 0.25f), eLayerType::Ground, L"SquareStone2Material");
			GameObject* bridge1
				= object::Instantiate<GameObject>(Vector3(58.2f, -0.4f, object::zBackGround), Vector2(0.9f, 0.9f), eLayerType::Ground, L"BridgeMaterial");
		}
		
		{
			GameObject* stoneOnLoad3
				= object::Instantiate<GameObject>(Vector3(67.5f, 2.6f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone1Material");
			GameObject* stoneOnLoad4
				= object::Instantiate<GameObject>(Vector3(67.5f, 2.1f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone4Material");
			GameObject* bridge2
				= object::Instantiate<GameObject>(Vector3(69.5f, 2.65f, object::zBackGround), Vector2(1.1f, 1.1f), eLayerType::Ground, L"BridgeMaterial");
			GameObject* stoneOnLoad5
				= object::Instantiate<GameObject>(Vector3(71.5f, 2.6f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone1Material");
			GameObject* stoneOnLoad6
				= object::Instantiate<GameObject>(Vector3(71.5f, 2.1f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone4Material");
		}

		// 이 구간에서만 흔들림 발생
		{
			StoneLoad* stoneLoad4
				= object::Instantiate<StoneLoad>(Vector4(62.8f, -2.0f, object::zBackGround, 0.4f), eLayerType::Ground, L"SquareStone3Material");
			StoneLoad* stoneLoad5
				= object::Instantiate<StoneLoad>(Vector3(64.7f, -0.3f, object::zBackGround) , Vector2(0.7f, 0.4f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad6
				= object::Instantiate<StoneLoad>(Vector3(70.7f, -0.3f, object::zBackGround), Vector2(0.7f, 0.4f) , eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad8
				= object::Instantiate<StoneLoad>(Vector3(74.7f, -3.55f, object::zBackGround), Vector2(0.4f, 0.7f), Vector2(1.0f, 1.0f), eLayerType::Ground, L"SquareStone2Material");
		}

		
		{
			GameObject* bridge3
				= object::Instantiate<GameObject>(Vector3(76.0f, -0.25f, object::zBackGround), Vector2(1.0f, 1.0f), eLayerType::Ground, L"BridgeMaterial");
			GameObject* stoneOnLoad7
				= object::Instantiate<GameObject>(Vector3(77.5f, -0.33f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone1Material");
			GameObject* stoneOnLoad8
				= object::Instantiate<GameObject>(Vector3(77.5f, -0.4f, object::zBackGround), Vector2(0.15f, 0.35f), Vector2(0.25f, 0.8f), eLayerType::Ground, L"SquareStone4Material");
			GameObject* bridge4
				= object::Instantiate<GameObject>(Vector3(79.0f, -0.25f, object::zBackGround), Vector2(1.0f, 1.0f), eLayerType::Ground, L"BridgeMaterial");
		}

		{
			StoneLoad* stoneLoad9
				= object::Instantiate<StoneLoad>(Vector3(77.5f, -5.5f, object::zBackGround), Vector2(0.7f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad10
				= object::Instantiate<StoneLoad>(Vector3(84.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad11
				= object::Instantiate<StoneLoad>(Vector3(90.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
		}

		{
			GameObject* stoneTop1
				= object::Instantiate<GameObject>(Vector3(98.2f, -0.6f, object::zBackGround), Vector2(0.3f, 0.4f), eLayerType::Ground, L"SquareStone3Material");
			GameObject* stoneTop2
				= object::Instantiate<GameObject>(Vector3(100.2f, -2.3f, object::zBackGround), Vector2(0.4f, 0.3f), eLayerType::Ground, L"SquareStone4Material");
			GameObject* stoneTop3
				= object::Instantiate<GameObject>(Vector3(102.4f, -3.7f, object::zBackGround), Vector2(0.3f, 0.4f), eLayerType::Ground, L"SquareStone3Material");
			GameObject* bridge
				= object::Instantiate<GameObject>(Vector3(100.7f, -5.5f, object::zBackGround), Vector2(1.3f, 1.0f), eLayerType::Ground, L"BridgeMaterial");
			GameObject* stoneTop4
				= object::Instantiate<GameObject>(Vector3(103.6f, -5.5f, object::zBackGround), Vector2(0.3f, 0.25f), eLayerType::Ground, L"SquareStone4Material");
			GameObject* stoneTop5
				= object::Instantiate<GameObject>(Vector3(104.8f, -2.6f, object::zBackGround), Vector2(0.3f, 0.6f), eLayerType::Ground, L"SquareStone2Material");
		}

		{
			StoneLoad* stoneLoad12
				= object::Instantiate<StoneLoad>(Vector3(96.0f, -5.5f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad13
				= object::Instantiate<StoneLoad>(Vector3(88.0f, -5.1f, object::zBackGround), Vector2(0.8f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad14
				= object::Instantiate<StoneLoad>(Vector3(88.14f, -4.7f, object::zBackGround), Vector2(0.6f, 0.3f), eLayerType::Ground, L"SquareStone1Material");
		}

		{
			StoneLoad* stoneLoad15
				= object::Instantiate<StoneLoad>(Vector3(99.0f, -8.23f, object::zBackGround), Vector2(0.3f, 0.6f), eLayerType::Ground, L"SquareStone2Material");
			StoneLoad* stoneLoad16
				= object::Instantiate<StoneLoad>(Vector3(100.0f, -9.5f, object::zBackGround), Vector2(0.2f, 0.6f), Vector2(0.4f, 1.0f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad17
				= object::Instantiate<StoneLoad>(Vector3(110.0f, -9.5f, object::zBackGround), Vector2(0.5f, 0.6f), eLayerType::Ground, L"SquareStone1Material");
			StoneLoad* stoneLoad18
				= object::Instantiate<StoneLoad>(Vector3(104.0f, -10.0f, object::zBackGround), Vector2(0.7f, 0.2f), eLayerType::Ground, L"SquareStone1Material");
		}

		{
			GameObject* topFill1
				= object::Instantiate<GameObject>(Vector4(101.2f, 0.8f, object::zBackGround, 0.6f), eLayerType::Ground_Fill, L"GroundFillMaterial");
			GameObject* topFill2
				= object::Instantiate<GameObject>(Vector3(103.6f, -2.0f, object::zBackGround), Vector2(0.25f, 0.7f), Vector2(0.3f, 1.0f), eLayerType::Ground_Fill, L"GroundFillMaterial");
		}

		GameObject::Initialize();
	}
	void StoneLoads::Update()
	{
		GameObject::Update();
	}
	void StoneLoads::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void StoneLoads::Render()
	{
		GameObject::Render();
	}
}