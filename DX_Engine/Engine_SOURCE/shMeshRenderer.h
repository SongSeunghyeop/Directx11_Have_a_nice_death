#pragma once
#include "shComponent.h"
#include "shMesh.h"
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

	private:
		Mesh* mMesh;
		Shader* mShader;
	};
}
