#include "shLobby.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

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
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"LobbyMaterial"));



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