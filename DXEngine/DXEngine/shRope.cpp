#include "shRope.h"
#include "shMeshRenderer.h"
#include "shTransform.h"

namespace sh
{
	Rope::Rope()
	{

	}
	Rope::~Rope()
	{

	}
	void Rope::Initialize()
	{
		this->AddComponent<Collider2D>();
		this->SetName(L"Rope");

		GameObject::Initialize();
	}
	void Rope::Update()
	{
		GameObject::Update();
	}
	void Rope::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Rope::Render()
	{
		GameObject::Render();
	}
}