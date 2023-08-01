#pragma once
#include "shScene.h"

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
	private:
	};
}
