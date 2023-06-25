#pragma once
#include "shScene.h"

namespace sh
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void Release() override;

	private:
		Player* Death;
		GameObject* backGround;
	};
}
