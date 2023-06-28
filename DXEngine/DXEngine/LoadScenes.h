#pragma once
#include "shSceneManager.h"
#include "shPlayScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\DXEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\DXEngine.lib")
#endif



//#include "..\DXEngine\\shPlayScene.h"
//#include "shSceneManager.h"
namespace sh
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
}