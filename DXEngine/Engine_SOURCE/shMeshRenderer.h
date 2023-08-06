#pragma once
#include "shComponent.h"
#include "shMesh.h"
#include "shMaterial.h"
#include "shShader.h"

namespace sh
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetMesh(std::shared_ptr<Mesh> mesh) { mMesh = mesh; }
		std::shared_ptr<Mesh> GetMesh() { return mMesh; }

		void SetColor(Vector4 color) { 
			textureColor.x = color.x / 255;
			textureColor.y = color.y / 255;
			textureColor.z = color.z / 255;
			textureColor.w = color.w;
		 }
		void SetMaterial(std::shared_ptr<Material> material) { mMaterial = material; }
		
		std::shared_ptr<Material> GetMaterial() { return mMaterial; }

		Vector2 GetTextureSize()
		{
			return mMaterial->GetTextureSize();
		}

		void BindConstantBuffer();
		void SetEnd(Vector2 point)
		{
			endPoint = point;
		}
		void Fliping(UINT f)
		{
			flipx = f;
		};
	private:
		Vector2 endPoint;

		std::shared_ptr<Mesh> mMesh;
		std::shared_ptr<Material> mMaterial;

		UINT flipx;

		Vector4 textureColor;
	};
}
