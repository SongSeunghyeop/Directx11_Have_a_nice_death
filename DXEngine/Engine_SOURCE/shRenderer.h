#pragma once
#include "DXEngine.h"
#include "shGraphicDevice_Dx11.h"
#include "shMesh.h"
#include "shShader.h"
#include "shConstantBuffer.h"
#include "shCameraController.h"

using namespace sh::graphics;
using namespace sh::math;
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

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[];

	extern std::vector<sh::CameraController*> cameras;
	extern std::shared_ptr<sh::Shader> spriteShader;
	extern std::shared_ptr<sh::Shader> girdShader;

	void Initialize();
	void Render();
	void Release();
}
