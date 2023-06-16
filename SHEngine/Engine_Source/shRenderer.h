#pragma once
#include "SHEngine.h"
#include "shGraphicDevice_Dx11.h"
#include "shMesh.h"
#include "shShader.h"
#include "shConstantBuffer.h"

using namespace sh::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern sh::Mesh* mesh;
	extern sh::Shader* shader;
	extern sh::graphics::ConstantBuffer* constantBuffer;

	void Initialize();
	void Release();
}
