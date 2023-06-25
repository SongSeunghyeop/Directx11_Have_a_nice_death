#include "shCameraController.h"
#include "shTransform.h"
#include "shGameObject.h"
#include "shTime.h"
#include "shInput.h"

namespace sh
{
	void CameraController::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Transform* targetPos = Target->GetComponent<Transform>();
		
		tr->SetPosition(targetPos->GetPosition() + Vector3(0.0f, 3.0f, -10.0f));
	}
}
