#pragma once
#include "shGameObject.h"
#include "shCameraController.h"

namespace sh
{
	class Camera : public GameObject
	{
	public:
		Camera(std::wstring type);
		~Camera();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		
		void SetTarget(GameObject* target);
	private:
		std::wstring CameraType;
		CameraController* cameraCont;

		GameObject* Target;
	};
}