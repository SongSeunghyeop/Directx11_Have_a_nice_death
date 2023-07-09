#include "shCamera.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shInput.h"
#include "shTime.h"

namespace sh
{
	Camera::Camera(std::wstring type)
	{
		this->SetName(L"Camera");
		Target = NULL;
		cameraCont = this->AddComponent<CameraController>();
		CameraType = type;
	}
	Camera::~Camera()
	{

	}

	void Camera::SetTarget(GameObject* target)
	{
		Target = target;
	}
	void Camera::Initialize()
	{
		if (CameraType == L"UI")
		{
			cameraCont->TurnLayerMask(eLayerType::UI, true);
		}

		if (CameraType == L"MAIN")
		{
			cameraCont->TurnLayerMask(eLayerType::Structure_F, true);
			cameraCont->TurnLayerMask(eLayerType::Structure_B, true);
			cameraCont->TurnLayerMask(eLayerType::Player, true);
			cameraCont->TurnLayerMask(eLayerType::BackGround, true);
			cameraCont->TurnLayerMask(eLayerType::Ground, true);
			cameraCont->SetProjectionType(CameraController::eProjectionType::Perspective);
		}

		GameObject::Initialize();
	}
	void Camera::Update()
	{
		if (Target != NULL)
		{
			Transform* Tr = this->GetComponent<Transform>();
			Vector3 TargetPos = Target->GetComponent<Transform>()->GetPosition();
			Tr->SetPosition(TargetPos + Vector3(0, 1.2, -5));
			GameObject::Update();
		}
	}
	void Camera::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Camera::Render()
	{
		GameObject::Render();
	}
}