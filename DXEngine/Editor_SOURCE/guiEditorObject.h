#pragma once
#include "..\\Engine_SOURCE\\shGameObject.h"


namespace gui
{
	class EditorObject : public sh::GameObject
	{
	public:
		EditorObject();
		virtual ~EditorObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}