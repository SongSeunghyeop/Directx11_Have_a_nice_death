#include "shPlayerController.h"
#include "shTransform.h"
#include "shGameObject.h"
#include "shTime.h"
#include "shInput.h"

namespace sh
{
	float speed = 3.0f;
	void PlayerController::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		
		if (Input::GetKey(eKeyCode::D))
		{
			pos += Vector3(speed * Time::DeltaTime(), 0, 0);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos += Vector3(-speed * Time::DeltaTime(), 0, 0);
		}

		tr->SetPosition(pos);
	}
}
