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

		animator->PlayAnimation(L"Elevator_NPCIdle1L", true);

		Tr->SetScale(4.8f, 4.8f, 1.0f);

		Light* lightComp = this->AddComponent<Light>();
		lightComp->SetType(eLightType::Point);
		lightComp->SetColor(Vector4(169, 245, 225, 1.0f));
		lightComp->SetRadius(3.0f);

		Collider2D* collider = this->AddComponent<Collider2D>();


		GameObject::Initialize();
	}
	void Elevator_NPC::Update()
	{
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