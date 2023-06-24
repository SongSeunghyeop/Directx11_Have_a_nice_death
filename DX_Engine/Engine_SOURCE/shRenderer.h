#pragma once
#include "DX_Engine.h"
#include "shGraphicDevice_Dx11.h"
#include "shMesh.h"
#include "shShader.h"
#include "shConstantBuffer.h"

using namespace sh::math;
using namespace sh::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Matrix mWorld;
		Matrix mView;
		Matrix mProjection;
	};

	extern Vertex vertexes[];
	extern sh::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	void Initialize();
	void Release();
}
