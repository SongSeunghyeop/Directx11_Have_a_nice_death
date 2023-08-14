#include "shFootHold.h"
#include "shTransform.h"
#include "shLight.h"
#include "shObject.h"
#include "shTime.h"
namespace sh
{
	FootHold::FootHold()
	{
		this->SetName(L"FootHold");
	}
	FootHold::~FootHold()
	{

	}
	void FootHold::Initialize()
	{
		this->AddComponent<Collider2D>()->SetSize(Vector2(0.3f, 0.3f));

		MeshRenderer* mr2 = this->AddComponent<MeshRenderer>();
		mr2->SetMaterial(Resources::Find<Material>(L"EmptyMaterial"));

		GameObject::Initialize();
	}
	void FootHold::Update()
	{
		GameObject::Update();
	}
	void FootHold::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void FootHold::Render()
	{
		GameObject::Render();
	}

	void FootHold::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			if (player->jumped)
			{
				player->playerRG->SetGround(false);

				if (player->activeState == Player::eMoveState::Run)
				{
					player->playerRG->SetGround(true);
					player->jumped = false;
				}
			}
			else
				player->playerRG->SetGround(true);

			player->Prev_pos.y = other->GetPosition().y;
			//
		}
	}
	void FootHold::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Elevator_NPC")
		{
			if (Input::GetKey(eKeyCode::F))
			{
				SceneManager::LoadScene(L"DungeonScene");
			}
		}

		if (other->GetOwner()->GetName() == L"Rope")
		{
			if (Input::GetKey(eKeyCode::W))
			{
				Vector3 pos = player->playerTR->GetPosition();

				pos.y += 50.0f * Time::DeltaTime();

				player->playerTR->SetPosition(pos);
			}
		}

		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			if (player->jumped)
				player->playerRG->SetGround(false);
			else
				player->playerRG->SetGround(true);

			float y0 = this->GetComponent<Collider2D>()->GetPosition().y;
			float y1 = this->GetComponent<Collider2D>()->GetPosition().y - this->GetComponent<Collider2D>()->GetScale().y / 2;
			float y2 = other->GetOwner()->GetComponent<Collider2D>()->GetPosition().y + other->GetOwner()->GetComponent<Collider2D>()->GetScale().y / 2;

			if (y1 < y2 - 0.07f)
			{
				Vector3 pos = player->GetComponent<Transform>()->GetPosition();
				pos.y += 10.0f * Time::DeltaTime();
				player->GetComponent<Transform>()->SetPosition(pos);
			}
		}
	}
	void FootHold::OnCollisionExit(Collider2D* other)
	{
		if (other->GetOwner()->getLayerType() == enums::eLayerType::Ground)
		{
			player->playerRG->SetGround(false);

			player->runSpeed = 13.0f;
		}
	}
}