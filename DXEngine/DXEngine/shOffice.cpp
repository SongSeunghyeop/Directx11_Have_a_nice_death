#include "shOffice.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"
#include "shBigColumn.h"
#include "shSmallColumn.h"

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
		GameObject* ground2
			= object::Instantiate<GameObject>(Vector4(60.0f, -6.2f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		GameObject* ground1
			= object::Instantiate<GameObject>(Vector4(38.5f, -6.2f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		GameObject* circlestair
			= object::Instantiate<GameObject>(Vector4(40.4f, -5.6f, object::zBackGround, 0.45f), eLayerType::Structure_F, L"CircleStairMaterial");
		SmallColumn* column1
			= object::Instantiate<SmallColumn>(Vector4(44.0f, -0.5f, object::zPlayer, 0.45f), eLayerType::Structure_F, L"ColumnMaterial");
		BigColumn* column2
			= object::Instantiate<BigColumn>(Vector4(46.0f, -0.4f, object::zPlayer, 0.9f), eLayerType::Structure_F, L"ColumnMaterial");
		GameObject* wall
			= object::Instantiate<GameObject>(Vector4(57.5f, -2.8f, object::zBackGround, 0.7f), eLayerType::Structure_F, L"WallMaterial");
		BigColumn* column3
			= object::Instantiate<BigColumn>(Vector4(63.0f, -0.4f, object::zPlayer, 0.9f), eLayerType::Structure_F, L"ColumnMaterial");
		GameObject* office
			= object::Instantiate<GameObject>(Vector4(67.5f, -1.8f, object::zBackGround, 1.1f), eLayerType::BackGround, L"OfficeMaterial");
		GameObject* pillar
			= object::Instantiate<GameObject>(Vector4(72.0f, -5.0f, object::zBackGround, 0.9f), eLayerType::Structure_B, L"PillarMaterial");

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