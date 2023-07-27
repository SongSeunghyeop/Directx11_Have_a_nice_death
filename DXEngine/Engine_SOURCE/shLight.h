#pragma once
#include "shComponent.h"
#include "shGraphics.h"

namespace sh
{
	using namespace graphics;
	class Light : public Component
	{
	public:
		Light();
		~Light();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		LightAttribute GetAttribute() { return mAttribute; }
		void SetType(eLightType rype) { mAttribute.type = rype; }
		void SetRadius(float radius) { mAttribute.radius = radius; }
		void SetAngle(float angle) { mAttribute.angle = angle; }
		void SetColor(Vector4 color) { 
			Vector4 conversion_color;
			conversion_color.x = color.x / 255;
			conversion_color.y = color.y / 255;
			conversion_color.z = color.z / 255;

			mAttribute.color = conversion_color;
		}
		Vector4 GetColor() { return mAttribute.color; }
		eLightType GetType() { return mAttribute.type; }
		float GetRadius() { return mAttribute.radius; }
		float GetAngle() { return mAttribute.angle; }

	private:
		LightAttribute mAttribute;
	};
}
