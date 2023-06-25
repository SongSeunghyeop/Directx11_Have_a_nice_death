#include "shLobby.h"
#include "shTransform.h"
#include "shPlayerController.h"

namespace sh
{
	Lobby::Lobby()
	{

	}
	Lobby::~Lobby()
	{
		
	}
	void Lobby::Initialize()
	{
		Lobby_MR = this->AddComponent<MeshRenderer>();
		Lobby_MR->SetMaterial(Resources::Find<Material>(L"LobbyMaterial"));

		this->GetComponent<Transform>()->SetScale(Vector3(15.0f, 10.0f, 0.0f));

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
	void Lobby::Release()
	{
		GameObject::Release();
	}
}