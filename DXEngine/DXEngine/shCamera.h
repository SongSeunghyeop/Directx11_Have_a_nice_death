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
		void SetFilmingPos(Vector3 pos)
		{
			filmingPos = pos;
		}
	private:
		std::wstring CameraType;
		CameraController* cameraCont;

		GameObject* Target;

		Vector3 filmingPos;
	};
}