#include "shPlaza.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"
#include "shSmallColumn.h"

namespace sh
{
	Plaza::Plaza()
	{
		this->SetName(L"Plaza");
	}
	Plaza::~Plaza()
	{

	}
	void Plaza::Initialize()
	{
		SmallColumn* column1
			= object::Instantiate<SmallColumn>(Vector4(27.5f, 0.3f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");

		SmallColumn* column2
			= object::Instantiate<SmallColumn>(Vector4(33.0f, 0.3f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"ColumnMaterial");

		GameObject* tree
			= object::Instantiate<GameObject>(Vector4(30.6f, -3.2f, object::zBackGround,1.0f), eLayerType::Structure_F, L"TreeMaterial");

		SmallColumn* column3
			= object::Instantiate<SmallColumn>(Vector4(34.0f, 0.4f, object::zPlayer, 0.6f), eLayerType::Structure_F, L"ColumnMaterial");

		GameObject::Initialize();
	}
	void Plaza::Update()
	{
		GameObject::Update();
	}
	void Plaza::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Plaza::Render()
	{
		GameObject::Render();
	}
}