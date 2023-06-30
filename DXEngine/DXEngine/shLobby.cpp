#include "shLobby.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

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
		MeshRenderer* mr = this->AddComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"LobbyMaterial"));
		this->GetComponent<Transform>()->SetScale(Vector3(12.0f, 7.0f, .0f));

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