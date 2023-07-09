#include "shOffice.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Office::Office()
	{

	}
	Office::~Office()
	{

	}
	void Office::Initialize()
	{
		/*GameObject* ground1
			= object::Instantiate<GameObject>(Vector3(21.0f, -1.0f, 0.7f), eLayerType::Structure, L"GroundMaterial");
		GameObject* ground2
			= object::Instantiate<GameObject>(Vector3(34.5f, -1.0f, 0.7f), eLayerType::Structure, L"GroundMaterial");
		CircleStair* circlestair
			= object::Instantiate<CircleStair>(Vector3(22.0f, -0.8f, 0.6f), eLayerType::Structure, L"CircleStairMaterial");
		Wall* wall
			= object::Instantiate<Wall>(Vector3(32.0, 0.9f, 0.6f), eLayerType::Structure, L"WallMaterial");
		Pillar* pillar
			= object::Instantiate<Pillar>(Vector3(42.0f, 1.1f, 0.6f), eLayerType::Structure, L"PillarMaterial");*/

		GameObject::Initialize();
	}
	void Office::Update()
	{
		GameObject::Update();
	}
	void Office::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Office::Render()
	{
		GameObject::Render();
	}
}