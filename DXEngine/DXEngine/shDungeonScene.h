#pragma once
#include "shScene.h"
#include "shPlayer.h"

namespace sh
{
	class DungeonScene : public Scene
	{
	public:
		DungeonScene();
		virtual ~DungeonScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:
	};
}
