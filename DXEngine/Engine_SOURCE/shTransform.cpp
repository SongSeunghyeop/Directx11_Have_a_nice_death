#include "shTransform.h"
#include "shRenderer.h"
#include "shConstantBuffer.h"
#include "shCameraController.h"

namespace sh
{
	using namespace sh::graphics;
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mPosition(Vector3::Zero)
		, mRotation(Vector3::Zero)
		, mScale(Vector3::One)
	{

	}

	Transform::~Transform()
	{

	}

	void Transform::Initialize()
	{

	}

	void Transform::Update()
	{
		// 이동 회전 크기 변경
	}

	void Transform::LateUpdate()
	{
		//월드좌표를 단위행렬로
		mWorld = Matrix::Identity;

		//현재의 로컬 좌표들을 전부 월드 좌표로 변환
		Matrix scale = Matrix::CreateScale(mScale);

		Matrix rotation;
		rotation = Matrix::CreateRotationX(mRotation.x);
		rotation *= Matrix::CreateRotationY(mRotation.y);
		rotation *= Matrix::CreateRotationZ(mRotation.z);

		Matrix position;
		position.Translation(mPosition);

		//mWorld에 저장, 나중에 상수버퍼에 전달
		mWorld = scale * rotation * position;

		mUp = Vector3::TransformNormal(Vector3::Up, rotation);
		mFoward = Vector3::TransformNormal(Vector3::Forward, rotation);
		mRight = Vector3::TransformNormal(Vector3::Right, rotation);

		if (mParent) // 부모 오브젝트가 있다면 
		{
			mWorld *= mParent->mWorld; // 그 부모클래스에 곱해준다 
		}
	}

	void Transform::Render()
	{

	}

	void Transform::BindConstantBuffer()
	{
		renderer::TransformCB trCB = {};
		trCB.mWorld = mWorld;
		trCB.mView = CameraController::GetGpuViewMatrix();
		trCB.mProjection = CameraController::GetGpuProjectionMatrix();

		//
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Transform];
		cb->SetData(&trCB);
		cb->Bind(eShaderStage::VS);
		cb->Bind(eShaderStage::HS);
		cb->Bind(eShaderStage::DS);
		cb->Bind(eShaderStage::GS);
		cb->Bind(eShaderStage::PS);
	}
}
