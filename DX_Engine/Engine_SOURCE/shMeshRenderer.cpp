#include "shMeshRenderer.h"
#include "shGameObject.h"
#include "shTransform.h"
#include "shRenderer.h"

namespace sh
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
		, mMesh(Resources::Find<Mesh>(L"RectMesh"))
	{ 

	}
	MeshRenderer::~MeshRenderer()
	{
}
	void MeshRenderer::Initialize()
	{
	}
	void MeshRenderer::Update()
	{
	}
	void MeshRenderer::LateUpdate()
	{
	}
	void MeshRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->BindConstantBuffer();

		mMesh->BindBuffer();
		mMaterial->Binds();
		mMesh->Render(); //DrawIndex

		mMaterial->Clear();
	}
	void MeshRenderer::Release()
	{
		
	}
}
