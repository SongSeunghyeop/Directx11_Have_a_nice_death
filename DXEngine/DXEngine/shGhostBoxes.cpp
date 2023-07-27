#include "shGhostBoxes.h"
#include "shObject.h"
#include "shGhostBox.h"
#include "shGhostBox2.h"
namespace sh
{
	GhostBoxes::GhostBoxes()
	{
		this->SetName(L"GhostBoxes");
	}
	GhostBoxes::~GhostBoxes()
	{

	}
	void GhostBoxes::Initialize()
	{
		{
			GhostBox2* ghostLongbox2
				= object::Instantiate<GhostBox2>(Vector3(49.2f, -6.7f, object::zBackGround), Vector2(0.9f, 1.3f), eLayerType::Structure_B, L"GhostBox3Material");
			GhostBox2* ghostLongbox3
				= object::Instantiate<GhostBox2>(Vector4(70.2f, 1.25f, object::zBackGround, 1.1f), eLayerType::Structure_B, L"GhostBox3Material");
		}

		{
			GhostBox* ghostbox1
				= object::Instantiate<GhostBox>(Vector4(27.0f, -6.0f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox2
				= object::Instantiate<GhostBox>(Vector4(31.0f, -7.0f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox3
				= object::Instantiate<GhostBox>(Vector4(37.5f, -7.0f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox4
				= object::Instantiate<GhostBox>(Vector4(42.0f, -7.0f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox5
				= object::Instantiate<GhostBox>(Vector4(46.9f, -7.0f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox6
				= object::Instantiate<GhostBox>(Vector4(52.3, -6.1f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox7
				= object::Instantiate<GhostBox>(Vector4(57.5f, -2.8f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox8
				= object::Instantiate<GhostBox>(Vector4(61.0f, -2.8f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox9
				= object::Instantiate<GhostBox>(Vector4(65.6f, 0.9f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");

			GhostBox* ghostbox10
				= object::Instantiate<GhostBox>(Vector4(76.7f, -4.1f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox11
				= object::Instantiate<GhostBox>(Vector4(79.5f, -4.1f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox12
				= object::Instantiate<GhostBox>(Vector4(87.3f, -3.3f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
			GhostBox* ghostbox13
				= object::Instantiate<GhostBox>(Vector4(93.5f, -4.1f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"GhostBox1Material");
		}
	

		GameObject::Initialize();
	}
	void GhostBoxes::Update()
	{
		GameObject::Update();
	}
	void GhostBoxes::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void GhostBoxes::Render()
	{
		GameObject::Render();
	}
}