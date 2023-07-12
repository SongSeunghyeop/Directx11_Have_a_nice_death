#include "shLobby.h"
#include "shLobbyScene.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shObject.h"
#include "shBigColumn.h"
#include "shSmallColumn.h"

namespace sh
{
	Lobby::Lobby()
	{
		this->SetName(L"Lobby");
	}
	Lobby::~Lobby()
	{

	}
	void Lobby::Initialize()
	{
		{
			GameObject* BossChair
				= object::Instantiate<GameObject>(Vector4(-0.5f, -2.0f, object::zBackGround,0.7f), eLayerType::Structure_B, L"BossChairMaterial");
			GameObject* Stair_R
				= object::Instantiate<GameObject>(Vector4(7.0, -5.45f, object::zBackGround, 0.7f), eLayerType::Structure_B, L"StairR_Material");
			GameObject* SupportDesk
				= object::Instantiate<GameObject>(Vector4(-0.25f, -5.4f, object::zBackGround, 1.0f), eLayerType::Structure_B, L"SupportDesk_Material");
			GameObject* BossDesk
				= object::Instantiate<GameObject>(Vector4(-0.2f, -3.8f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"BossDeskMaterial");
		}
		{
			BigColumn* column1
				= object::Instantiate<BigColumn>(Vector4(14.0f, -0.4f, object::zPlayer, 0.9f), eLayerType::Structure_F, L"ColumnMaterial");
			SmallColumn* column2
			= object::Instantiate<SmallColumn>(Vector4(7.4f, 2.0f, object::zBackGround, 0.8f), eLayerType::Structure_B, L"ColumnMaterial");
			SmallColumn* column3
				= object::Instantiate<SmallColumn>(Vector4(15.0f, 2.0f, object::zBackGround, 0.8f), eLayerType::Structure_B, L"ColumnMaterial");
		}

		GameObject::Initialize();
	}
	void Lobby::Update()
	{
		GameObject::Update();
	}
	void Lobby::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Lobby::Render()
	{
		GameObject::Render();
	}
}