#pragma once
#include "shScene.h"
#include "shPlayer.h"

namespace sh
{
	class LobbyScene : public Scene
	{
	public:
		LobbyScene();
		virtual ~LobbyScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		Camera* GetMainCamera()
		{
			return mainCamera;
		}

	private:
		Camera* mainCamera;
	};
}