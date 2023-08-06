#include "shCamera.h"
#include "shMeshRenderer.h"
#include "shTransform.h"
#include "shInput.h"
#include "shTime.h"
#include "shRenderer.h"

namespace sh
{
	Camera::Camera(std::wstring type)
	{
		this->SetName(L"Camera");
		Target = NULL;
		cameraCont = this->AddComponent<CameraController>();
		CameraType = type;
		renderer::cameras.push_back(cameraCont);

		filmingPos = Vector3(0, 1.0, -7);
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
			cameraCont->SetProjectionType(CameraController::eProjectionType::Perspective);
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
		if (CameraType == L"MAIN")
		{
			Transform* Tr = this->GetComponent<Transform>();

			Vector3 TargetPos = Target->GetComponent<Transform>()->GetPosition();

			Tr->SetPosition(TargetPos + filmingPos);
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