#include "shStoneLoad.h"
#include "shTransform.h"
#include "shMeshRenderer.h"
#include "shObject.h"
#include "shMaterial.h"
#include "shResources.h"

namespace sh
{
	StoneLoad::StoneLoad()
	{

	}
	StoneLoad::~StoneLoad()
	{

	}
	void StoneLoad::Initialize()
	{
		this->AddComponent<Collider2D>();
		if(this->GetMaterialName() == L"SquareStone1Material")
		{

			Transform* Tr = this->GetComponent<Transform>();
			MeshRenderer* Mr = this->GetComponent<MeshRenderer>();
			float scale = this->GetDrainage().x;
			Vector3 Pos = Tr->GetPosition();
		
			float Load_length = Mr->GetTextureSize().x / 100.0f * scale;

			std::shared_ptr<Material> groundFill = Resources::Find<Material>(L"GroundFillMaterial");
			float groundFill_TextureLengthX = groundFill->GetTextureSize().x;
			float groundFill_ScaleX;
			float groundFill_TextureLengthY = groundFill->GetTextureSize().y;
			float groundFill_ScaleY = groundFill_TextureLengthY / 100 * 1.2f;

			 groundFill_ScaleX = Load_length * 100 / groundFill_TextureLengthX;

			GameObject* groundFill1
				= object::Instantiate<GameObject>(Vector3(Pos.x, Pos.y - groundFill_ScaleY / 2, Pos.z),Vector2(groundFill_ScaleX,1.2f),Vector2(groundFill_ScaleX / 1.2f,1.0f), eLayerType::Ground_Fill, L"GroundFillMaterial");
		}
		GameObject::Initialize();
	}
	void StoneLoad::Update()
	{
		GameObject::Update();
	}
	void StoneLoad::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void StoneLoad::Render()
	{
		GameObject::Render();
	}
}