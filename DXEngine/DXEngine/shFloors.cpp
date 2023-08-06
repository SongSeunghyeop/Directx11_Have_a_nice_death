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
		GameObject* floor1
			= object::Instantiate<GameObject>(Vector4(79.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor1->AddComponent<Collider2D>()->SetSize(Vector2(1.0f, 1.0f));
		GameObject* floor2
			= object::Instantiate<GameObject>(Vector4(59.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor2->AddComponent<Collider2D>()->SetSize(Vector2(1.0f, 1.0f));
		GameObject* floor3
			= object::Instantiate<GameObject>(Vector4(39.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor3->AddComponent<Collider2D>()->SetSize(Vector2(1.0f, 1.0f));
		GameObject* floor4
			= object::Instantiate<GameObject>(Vector4(19.0f, -6.5f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		floor4->AddComponent<Collider2D>()->SetSize(Vector2(1.0f, 1.0f));

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