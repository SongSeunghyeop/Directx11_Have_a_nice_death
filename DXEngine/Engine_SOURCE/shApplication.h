#pragma once
#include "DXEngine.h"
#include "shGraphicDevice_Dx11.h"
#include "shScene.h"

namespace sh
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Run();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();
		void Destroy();
		void Present();

		void SetWindow(HWND hwnd, UINT width, UINT height, Vector2 pos);

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HWND GetHwnd() { return mHwnd; }

	private:
		bool mbInitialize = false;
		std::unique_ptr<sh::graphics::GraphicDevice_Dx11> graphicDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;
	};
}
