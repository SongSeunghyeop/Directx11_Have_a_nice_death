#include "shObject.h"
#include "shGhostBox2.h"
#include "shLight.h"
namespace sh
{
	GhostBox2::GhostBox2()
	{
		this->SetName(L"GhostBox2");
	}
	GhostBox2::~GhostBox2()
	{

	}
	void GhostBox2::Initialize()
	{
		Transform* Tr = this->GetComponent<Transform>();
		float scalex = this->GetDrainage().x;
		float scaley = this->GetDrainage().y;
		enums::eLayerType type = this->getLayerType();

		GameObject* ghostbox2
			= object::Instantiate<GameObject>(Vector3(Tr->GetPosition().x, Tr->GetPosition().y, Tr->GetPosition().z), Vector2(scalex + 0.1f, scaley + 0.1f), type, L"GhostBox4Material");

		GameObject::Initialize();
	}
	void GhostBox2::Update()
	{
		GameObject::Update();
	}
	void GhostBox2::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void GhostBox2::Render()
	{
		GameObject::Render();
	}
}