#include "shGameObject.h"
#include "shRenderer.h"
#include "shGraphicDevice_Dx11.h"
#include "shTransform.h"

namespace sh
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}

		for (Script* script : mScripts)
		{
			script->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			script->LateUpdate();
		}
	}

	void GameObject::Render()
	{
		for (Component* comp : mComponents)
		{
			comp->Render();
		}
		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.

		for (Script* script : mScripts)
		{
			script->Render();
		}
	}

	void GameObject::Release()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
		}
		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.

		for (Script* script : mScripts)
		{
			delete script;
		}
	}
}
