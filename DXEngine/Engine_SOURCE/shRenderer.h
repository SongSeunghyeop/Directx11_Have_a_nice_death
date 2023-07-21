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

	CBUFFER(AnimatorCB, CBSLOT_ANIMATION2D)
	{
		Vector2 spriteLeftTop;
		Vector2 spriteSize;
		Vector2 spriteOffset;
		Vector2 atlasSize;
	};

	CBUFFER(UVCB, CBSLOT_SETUV)
	{
		float EndX;
		float EndY;
	};

	extern sh::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[];

	extern sh::CameraController* mainCamera;
	extern std::vector<sh::CameraController*> cameras;
	extern std::vector<DebugMesh> debugMeshs;

	extern std::shared_ptr<sh::Shader> shader;

	void Initialize();
	void Render();
	void Release();

	void PushDebugMeshAttribute(DebugMesh mesh);
}
