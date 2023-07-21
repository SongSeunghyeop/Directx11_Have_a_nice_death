#include "shMeshRenderer.h"
#include "shGameObject.h"
#include "shTransform.h"
#include "shRenderer.h"
#include "shResources.h"


namespace sh
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
		, mMesh(Resources::Find<Mesh>(L"RectMesh"))
		, endPoint(Vector2(1.0f,1.0f))
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

		this->BindConstantBuffer();

		mMesh->BindBuffer();
		mMaterial->Binds();
		mMesh->Render();

		mMaterial->Clear();
	}

	void MeshRenderer::BindConstantBuffer()
	{
		renderer::UVCB uvCB = {};
		uvCB.EndX = endPoint.x;
		uvCB.EndY = endPoint.y;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::SetUV];
		cb->SetData(&uvCB);
		cb->Bind(eShaderStage::VS);
	}
}
