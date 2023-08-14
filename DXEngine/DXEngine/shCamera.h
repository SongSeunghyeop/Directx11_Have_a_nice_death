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
		
		void SetFilmingPos(Vector3 pos)
		{
			filmingPos = pos;
		}
		CameraController* getCameraCont()
		{
			return cameraCont;
		}
	private:
		std::wstring CameraType;
		CameraController* cameraCont;

		Vector3 filmingPos;
	};
}