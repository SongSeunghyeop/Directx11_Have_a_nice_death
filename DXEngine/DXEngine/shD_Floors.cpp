#include "shD_Floors.h"
#include "shObject.h"

namespace sh
{
	D_Floors::D_Floors()
	{
		this->SetName(L"D_Floors");
	}
	D_Floors::~D_Floors()
	{

	}
	void D_Floors::Initialize()
	{
		{
			GameObject* floor2
				= object::Instantiate<GameObject>(Vector4(-22.0f, -4.7f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
			floor2->AddComponent<Collider2D>();
			GameObject* floor1_Under
				= object::Instantiate<GameObject>(Vector4(0.5f, -5.8f, object::zBackGround, 1.6f), eLayerType::Ground, L"GroundMaterial");
			floor1_Under->AddComponent<Collider2D>();
			GameObject* floor2_Under
				= object::Instantiate<GameObject>(Vector4(-17.5f, -5.8f, object::zBackGround, 1.6f), eLayerType::Ground, L"GroundMaterial");
			GameObject* RockBG1
				= object::Instantiate<GameObject>(Vector3(-0.8f, -6.3f, object::zBackGround), Vector2(1.3f, 1.0f), eLayerType::Structure_F, L"RockBG06_Material");
			GameObject* RockBG2
				= object::Instantiate<GameObject>(Vector3(8.2f, -6.3f, object::zBackGround), Vector2(1.3f, 1.0f), eLayerType::Structure_B, L"RockBG06_Material");
		}

		GameObject::Initialize();
	}
	void D_Floors::Update()
	{
		GameObject::Update();
	}
	void D_Floors::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void D_Floors::Render()
	{
		GameObject::Render();
	}
}