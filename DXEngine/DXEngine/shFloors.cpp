#include "shFloors.h"
#include "shObject.h"

namespace sh
{
	Floors::Floors()
	{
		this->SetName(L"Floors");
	}
	Floors::~Floors()
	{

	}
	void Floors::Initialize()
	{
		GameObject* floor2
			= object::Instantiate<GameObject>(Vector4(39.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor2->AddComponent<Collider2D>();
		GameObject* floor3
			= object::Instantiate<GameObject>(Vector4(19.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor3->AddComponent<Collider2D>();
		GameObject::Initialize();
	}
	void Floors::Update()
	{
		GameObject::Update();
	}
	void Floors::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Floors::Render()
	{
		GameObject::Render();
	}
}