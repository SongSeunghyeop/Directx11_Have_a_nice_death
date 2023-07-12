#pragma once
#include "shSceneManager.h"
#include "shTitleScene.h"
#include "shMenuScene.h"
#include "shLobbyScene.h"
#include "shDungeonScene.h"

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
		SceneManager::CreateScene<DungeonScene>(L"DungeonScene");
		SceneManager::CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}