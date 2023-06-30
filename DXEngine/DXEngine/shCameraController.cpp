#include "shCameraController.h"
#include "shTransform.h"
#include "shGameObject.h"

namespace sh
{
	CameraController::CameraController()
	{
		target = NULL;
	}
	void CameraController::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 targetpos;

		targetpos = target->GetComponent<Transform>()->GetPosition();

		Vector3 CameraPos = Vector3(0, 0, -5);

		tr->SetPosition(targetpos + CameraPos);
	}
}
