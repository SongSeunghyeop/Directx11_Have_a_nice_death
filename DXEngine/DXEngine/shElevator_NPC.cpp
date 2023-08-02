#include "shObject.h"
#include "shElevator_NPC.h"

namespace sh
{
	Elevator_NPC::Elevator_NPC()
	{
		this->SetName(L"Elevator_NPC");
	}
	Elevator_NPC::~Elevator_NPC()
	{

	}
	void Elevator_NPC::Initialize()
	{
		animator = this->AddComponent<Animator>();

		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Appear1");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Appear2");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Appear3");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Appear4");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Confirm1");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Confirm2");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Disappear");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Idle1");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Idle2");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Idle3");
		animator->SetAnimations(L"..\\Resources\\Texture\\Elevator_NPC\\Idle4");

		animator->CreateAnimations();

		Transform* Tr = this->GetComponent<Transform>();
		eLayerType type = this->getLayerType();
		Vector2 scale;
		scale.x = this->GetDrainage().x;
		scale.y = this->GetDrainage().y;

		animator->PlayAnimation(L"Elevator_NPCAppear1R", true);

		/*GameObject* Elevator
			= object::Instantiate<GameObject>(Vector3(Tr->GetPosition().x, Tr->GetPosition().y + 0.2f, Tr->GetPosition().z), Vector2(scale.x, scale.y), type, L"Elevator_Material");*/

		GameObject::Initialize();
	}
	void Elevator_NPC::Update()
	{
		this->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f,1.0f));
		GameObject::Update();
	}
	void Elevator_NPC::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Elevator_NPC::Render()
	{
		GameObject::Render();
	}
}