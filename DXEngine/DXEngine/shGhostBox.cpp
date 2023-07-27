#include "shObject.h"
#include "shGhostBox.h"
#include "shLight.h"

namespace sh
{
	GhostBox::GhostBox()
	{
		this->SetName(L"GhostBox");
	}
	GhostBox::~GhostBox()
	{

	}
	void GhostBox::Initialize()
	{
		Transform* Tr = this->GetComponent<Transform>();
		float scalex = this->GetDrainage().x;
		float scaley = this->GetDrainage().y;
		enums::eLayerType type = this->getLayerType();

		Light* lightComp = this->AddComponent<Light>();
		lightComp->SetType(eLightType::Point);
		lightComp->SetColor(Vector4(206, 246, 236, 1.0f));
		lightComp->SetRadius(2.0f);

		GameObject* ghostbox2
			= object::Instantiate<GameObject>(Vector3(Tr->GetPosition().x, Tr->GetPosition().y + 0.2f, Tr->GetPosition().z), Vector2(scalex, scaley), type, L"GhostBox2Material");
		
		GameObject::Initialize();
	}
	void GhostBox::Update()
	{
		GameObject::Update();
	}
	void GhostBox::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void GhostBox::Render()
	{
		GameObject::Render();
	}
}