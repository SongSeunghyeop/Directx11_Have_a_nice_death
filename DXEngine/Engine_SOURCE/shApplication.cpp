#include "shApplication.h"
#include "shInput.h"
#include "shTime.h"
#include "shRenderer.h"
#include "shSceneManager.h"

namespace sh
{
	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Initialize()
	{
		Time::Initiailize();
		Input::Initialize();

		//매쉬, 버택스, 메터리얼, 텍스쳐 생성, 정점 정보, 샘플러 레이터라이저 등 설정
		renderer::Initialize();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Time::Render();

		graphicDevice->ClearTarget();
		graphicDevice->UpdateViewPort();

		renderer::Render();

		graphicDevice->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Present()
	{
		graphicDevice->Present();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height, Vector2 pos)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<sh::graphics::GraphicDevice_Dx11>();
			sh::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, pos.x, pos.y, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}
