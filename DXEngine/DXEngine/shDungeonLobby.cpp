#include "shDungeonLobby.h"
#include "shBigColumn.h"
#include "shObject.h"
#include "shSmallColumn.h"

namespace sh
{
	DungeonLobby::DungeonLobby()
	{
		this->SetName(L"DungeonLobby");
	}
	DungeonLobby::~DungeonLobby()
	{

	}
	void DungeonLobby::Initialize()
	{
		GameObject* broken_Ev
			= object::Instantiate<GameObject>(Vector4(-13.0f, -2.9f, object::zBackGround, 1.2f), eLayerType::Structure_F, L"Broken_ElevatorMaterial");
		
		{
			GameObject* ground1
				= object::Instantiate<GameObject>(Vector4(-2.0f, -5.6f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
			GameObject* ground2
				= object::Instantiate<GameObject>(Vector4(-22.0f, -5.6f, object::zBackGround, 1.5f), eLayerType::Ground, L"GroundMaterial");
		}

		{
		GameObject* bigspot
			= object::Instantiate<GameObject>(Vector4(4.4f, 1.7f, object::zBackGround, 1.1f), eLayerType::Structure_F, L"BigSpotMaterial");
			GameObject* logo
				= object::Instantiate<GameObject>(Vector4(5.1f, -0.3f, object::zBackGround, 1.2f), eLayerType::Structure_F, L"LogoMaterial");
			GameObject* deskWall
				= object::Instantiate<GameObject>(Vector4(4.9f, -4.2f, object::zBackGround, 1.3f), eLayerType::Structure_B, L"DeskWallMaterial");
			GameObject* desk
				= object::Instantiate<GameObject>(Vector4(4.8f, -4.3f, object::zBackGround, 1.2f), eLayerType::Structure_B, L"DeskMaterial");
		}

		{
			GameObject* weapons
				= object::Instantiate<GameObject>(Vector4(-1.8f, -3.0f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"WeaponsMaterial");
			GameObject* skull1
				= object::Instantiate<GameObject>(Vector4(-1.8f, -1.9f, object::zBackGround, 1.1f), eLayerType::Structure_F, L"Skull1Material");
			GameObject* skull2
				= object::Instantiate<GameObject>(Vector4(-1.8f, -4.6f, object::zBackGround, 1.1f), eLayerType::Structure_B, L"Skull2Material");
		}

		{
			GameObject* SmallColumnDown
				= object::Instantiate<GameObject>(Vector4(12.0f, -3.8f, object::zBackGround, 0.6f), eLayerType::Structure_B, L"ColumnDownMaterial");
			GameObject* BigColumnDown
				= object::Instantiate<GameObject>(Vector4(13.0f, -4.5f, object::zPlayer, 0.9f), eLayerType::Structure_F, L"ColumnDownMaterial");
		}

		GameObject::Initialize();
	}
	void DungeonLobby::Update()
	{
		GameObject::Update();
	}
	void DungeonLobby::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void DungeonLobby::Render()
	{
		GameObject::Render();
	}
}