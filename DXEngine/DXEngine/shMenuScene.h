#pragma once
//#include "shScene.h"
#include <shScene.h>

namespace sh
{
	class MenuScene : public Scene
	{
	public:
		MenuScene();
		virtual ~MenuScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
