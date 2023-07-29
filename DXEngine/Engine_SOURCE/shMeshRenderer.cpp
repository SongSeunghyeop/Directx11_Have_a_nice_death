#include "shMeshRenderer.h"
#include "shGameObject.h"
#include "shTransform.h"
#include "shRenderer.h"
#include "shAnimator.h"

namespace sh
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
		, mMesh(Resources::Find<Mesh>(L"RectMesh"))
		, endPoint(Vector2(1.0f,1.0f))
		, flipx(1)
		, textureColor(Vector4(0.0f,0.0f,0.0f,0.0f))
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

		this->BindConstantBuffer();
		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (animator)
		{
			animator->Binds();
		}

		mMesh->Render();
		mMaterial->Clear();
	}

	void MeshRenderer::BindConstantBuffer()
	{
		renderer::UVCB uvCB = {};
		uvCB.EndX = endPoint.x;
		uvCB.EndY = endPoint.y;
		ConstantBuffer* cb1 = renderer::constantBuffer[(UINT)eCBType::SetUV];
		cb1->SetData(&uvCB);
		cb1->Bind(eShaderStage::VS);

		renderer::FlipCB fpCB = {};
		fpCB.flipX = flipx;
		ConstantBuffer* cb2 = renderer::constantBuffer[(UINT)eCBType::FlipX];
		cb2->SetData(&fpCB);
		cb2->Bind(eShaderStage::PS);

		if (textureColor != Vector4(0.0f, 0.0f, 0.0f, 0.0f))
		{
			renderer::ColorCB coCB = {};
			coCB.colorInfo = textureColor;
			coCB.colorDown = 1;
			ConstantBuffer* cb3 = renderer::constantBuffer[(UINT)eCBType::SetColor];
			cb3->SetData(&coCB);
			cb3->Bind(eShaderStage::PS);
		}
		else
		{
			renderer::ColorCB coCB = {};
			coCB.colorDown = 0;
			ConstantBuffer* cb3 = renderer::constantBuffer[(UINT)eCBType::SetColor];
			cb3->SetData(&coCB);
			cb3->Bind(eShaderStage::PS);
		}
	}
}
