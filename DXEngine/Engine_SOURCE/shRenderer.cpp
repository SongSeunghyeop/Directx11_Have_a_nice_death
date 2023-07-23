#include "shRenderer.h"
#include "shTexture.h"
#include "shMaterial.h"

namespace renderer
{
	using namespace sh;
	using namespace sh::graphics;

	std::shared_ptr<sh::Shader> shader;

	sh::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};

	//
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End] = {};
	
	//
	std::vector<sh::CameraController*> cameras = {};
	std::vector<DebugMesh> debugMeshs = {};
	sh::CameraController* mainCamera = nullptr;

	void SetupState()
	{
#pragma region InputLayout
		// Input layout 정점 구조 정보를 넘겨줘야한다.
		D3D11_INPUT_ELEMENT_DESC arrLayout[3] = {};

		arrLayout[0].AlignedByteOffset = 0;
		arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		arrLayout[0].InputSlot = 0;
		arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[0].SemanticName = "POSITION";
		arrLayout[0].SemanticIndex = 0;

		arrLayout[1].AlignedByteOffset = 12;
		arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		arrLayout[1].InputSlot = 0;
		arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[1].SemanticName = "COLOR";
		arrLayout[1].SemanticIndex = 0;

		arrLayout[2].AlignedByteOffset = 28;
		arrLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
		arrLayout[2].InputSlot = 0;
		arrLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[2].SemanticName = "TEXCOORD";
		arrLayout[2].SemanticIndex = 0;

		shader = sh::Resources::Find<Shader>(L"TriangleShader");
		sh::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = sh::Resources::Find<Shader>(L"SpriteShader");
		sh::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

		shader = sh::Resources::Find<Shader>(L"DebugShader");
		sh::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, shader->GetVSCode()
			, shader->GetInputLayoutAddressOf());

#pragma endregion
#pragma region Sampler State
		//Sampler State //
		D3D11_SAMPLER_DESC samplerDesc = {};
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Point].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 0, samplerState[(UINT)eSamplerType::Point].GetAddressOf());

		samplerDesc.Filter = D3D11_FILTER_ANISOTROPIC;
		GetDevice()->CreateSamplerState(&samplerDesc, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
		GetDevice()->BindSampler(eShaderStage::PS, 1, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
#pragma endregion
#pragma region Rasterizer State
		// FillMode = 폴리곤 내부를 어떻게 채울 것인가
		// CullMode = 어디를 컬링 작업 할 것인가 (Back = 뒷면 제거)
		D3D11_RASTERIZER_DESC rasterizerDesc = {};
		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_BACK;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidBack].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_FRONT;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidFront].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::SolidNone].GetAddressOf());

		rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_WIREFRAME;
		rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		GetDevice()->CreateRasterizeState(&rasterizerDesc
			, rasterizerStates[(UINT)eRSType::WireframeNone].GetAddressOf());
#pragma endregion
#pragma region Depth Stencil State
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};

		//less = 깊이가 작은 순서
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS_EQUAL;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::Less].GetAddressOf());


		//Greater = 깊이가 높은 순서
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_GREATER;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::Greater].GetAddressOf());

		//No Write
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::NoWrite].GetAddressOf());

		//None
		depthStencilDesc.DepthEnable = false;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS_EQUAL;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		depthStencilDesc.StencilEnable = false;

		GetDevice()->CreateDepthStencilState(&depthStencilDesc
			, depthStencilStates[(UINT)eDSType::None].GetAddressOf());
#pragma endregion
#pragma region Blend State
		D3D11_BLEND_DESC blendDesc = {};
		
		//default
		blendStates[(UINT)eBSType::Default] = nullptr;
		
		// Alpha Blend
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;
		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		GetDevice()->CreateBlendState(&blendDesc
			, blendStates[(UINT)eBSType::AlphaBlend].GetAddressOf());

		// one one
		blendDesc.AlphaToCoverageEnable = false;
		blendDesc.IndependentBlendEnable = false;

		blendDesc.RenderTarget[0].BlendEnable = true;
		blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		GetDevice()->CreateBlendState(&blendDesc
			, blendStates[(UINT)eBSType::OneOne].GetAddressOf());

#pragma endregion
	}
	void LoadMesh()
	{
		std::vector<Vertex> vertexes = {};
		std::vector<UINT> indexes = {};

		//RECT
		vertexes.resize(4);
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		vertexes[0].uv = Vector2(0.0f, 0.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes[1].uv = Vector2(1.0f, 0.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		vertexes[2].uv = Vector2(1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		vertexes[3].uv = Vector2(0.0f, 1.0f);

		// Vertex Buffer
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		Resources::Insert(L"RectMesh", mesh);

		mesh->CreateVertexBuffer(vertexes.data(), vertexes.size());

		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Rect Debug Mesh
		std::shared_ptr<Mesh> rectDebug = std::make_shared<Mesh>();
		Resources::Insert(L"DebugRect", rectDebug);
		rectDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		rectDebug->CreateIndexBuffer(indexes.data(), indexes.size());

		// Circle Debug Mesh
		vertexes.clear();
		indexes.clear();

		Vertex center = {};
		center.pos = Vector3(0.0f, 0.0f, 0.0f);
		center.color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		vertexes.push_back(center);

		int iSlice = 40;
		float fRadius = 0.5f;
		float fTheta = XM_2PI / (float)iSlice;

		for (int i = 0; i < iSlice; ++i)
		{
			center.pos = Vector3(fRadius * cosf(fTheta * (float)i)
				, fRadius * sinf(fTheta * (float)i)
				, 0.0f);
			center.color = Vector4(0.0f, 1.0f, 0.0f, 1.f);
			vertexes.push_back(center);
		}

		for (int i = 0; i < vertexes.size() - 2; ++i)
		{
			indexes.push_back(i + 1);
		}
		indexes.push_back(1);

		std::shared_ptr<Mesh> circleDebug = std::make_shared<Mesh>();
		Resources::Insert(L"DebugCircle", circleDebug);
		circleDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		circleDebug->CreateIndexBuffer(indexes.data(), indexes.size());
	}
	void LoadBuffer()
	{
		// Constant Buffer
		constantBuffer[(UINT)eCBType::Transform] = new ConstantBuffer(eCBType::Transform); //상수 버퍼
		constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));

		constantBuffer[(UINT)eCBType::Animator] = new ConstantBuffer(eCBType::Animator);
		constantBuffer[(UINT)eCBType::Animator]->Create(sizeof(AnimatorCB));

		constantBuffer[(UINT)eCBType::SetUV] = new ConstantBuffer(eCBType::SetUV);
		constantBuffer[(UINT)eCBType::SetUV]->Create(sizeof(UVCB));
	}

	void LoadShader() // 쉐이더 생성
	{
		std::shared_ptr<Shader> shader1 = std::make_shared<Shader>();
		shader1->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader1->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
		sh::Resources::Insert(L"TriangleShader", shader1);

		std::shared_ptr<Shader> shader2 = std::make_shared<Shader>();
		shader2->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		shader2->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		sh::Resources::Insert(L"SpriteShader", shader2);

		std::shared_ptr<Shader> debugShader = std::make_shared<Shader>();
		debugShader->Create(eShaderStage::VS, L"DebugVS.hlsl", "main");
		debugShader->Create(eShaderStage::PS, L"DebugPS.hlsl", "main");
		debugShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		debugShader->SetRSState(eRSType::WireframeNone);
		sh::Resources::Insert(L"DebugShader", debugShader);
	}

	void LoadMaterial()
	{
		std::shared_ptr<Shader> spriteShader
			= Resources::Find<Shader>(L"SpriteShader");

		std::shared_ptr<Shader> debugShader
			= Resources::Find<Shader>(L"DebugShader");

		//메터리얼을 만들고 로드한 텍스쳐와 스프라이트 쉐이더를 세팅한다
		sh::Material::Make_Material(spriteShader, L"Death", L"PlayerMaterial");
		sh::Material::Make_Material(spriteShader, L"Lobby", L"LobbyMaterial");
		sh::Material::Make_Material(spriteShader, L"Office", L"OfficeMaterial");
		sh::Material::Make_Material(spriteShader, L"Dungeon_Lobby", L"DungeonLobbyMaterial");
		sh::Material::Make_Material(spriteShader, L"title", L"TitleMaterial");
		sh::Material::Make_Material(spriteShader, L"Menu", L"MenuMaterial");
		sh::Material::Make_Material(spriteShader, L"Column", L"ColumnMaterial");
		sh::Material::Make_Material(spriteShader, L"Column2", L"Column2Material");
		sh::Material::Make_Material(spriteShader, L"Column3", L"Column3Material");
		sh::Material::Make_Material(spriteShader, L"Big_Rock", L"BigRockMaterial");
		sh::Material::Make_Material(spriteShader, L"Ground", L"GroundMaterial");
		sh::Material::Make_Material(spriteShader, L"Tree", L"TreeMaterial");
		sh::Material::Make_Material(spriteShader, L"Wall", L"WallMaterial");
		sh::Material::Make_Material(spriteShader, L"Pillar", L"PillarMaterial");
		sh::Material::Make_Material(spriteShader, L"CircleStair", L"CircleStairMaterial");
		sh::Material::Make_Material(spriteShader, L"BossChair", L"BossChairMaterial");
		sh::Material::Make_Material(spriteShader, L"BossDesk", L"BossDeskMaterial");
		sh::Material::Make_Material(spriteShader, L"Stair_R", L"StairR_Material");
		sh::Material::Make_Material(spriteShader, L"SupportDesk", L"SupportDesk_Material");
		sh::Material::Make_Material(spriteShader, L"BigSpot", L"BigSpotMaterial");
		sh::Material::Make_Material(spriteShader, L"Desk", L"DeskMaterial");
		sh::Material::Make_Material(spriteShader, L"DeskWall", L"DeskWallMaterial");
		sh::Material::Make_Material(spriteShader, L"Weapons", L"WeaponsMaterial");
		sh::Material::Make_Material(spriteShader, L"Skull1", L"Skull1Material");
		sh::Material::Make_Material(spriteShader, L"Skull2", L"Skull2Material");
		sh::Material::Make_Material(spriteShader, L"Logo", L"LogoMaterial");
		sh::Material::Make_Material(spriteShader, L"Broken_Elevator", L"Broken_ElevatorMaterial");
		sh::Material::Make_Material(spriteShader, L"Elevator", L"Elevator_Material");
		sh::Material::Make_Material(spriteShader, L"ColumnDown", L"ColumnDownMaterial");
		sh::Material::Make_Material(spriteShader, L"SquareStone1", L"SquareStone1Material");
		sh::Material::Make_Material(spriteShader, L"SquareStone2", L"SquareStone2Material");
		sh::Material::Make_Material(spriteShader, L"SquareStone3", L"SquareStone3Material");
		sh::Material::Make_Material(spriteShader, L"SquareStone4", L"SquareStone4Material");
		sh::Material::Make_Material(spriteShader, L"Corne1", L"Corne1Material");
		sh::Material::Make_Material(spriteShader, L"Corne2", L"Corne2Material");
		sh::Material::Make_Material(spriteShader, L"CircleGround", L"CircleGroundMaterial");
		sh::Material::Make_Material(spriteShader, L"Ground_Fill", L"GroundFillMaterial");
		sh::Material::Make_Material(spriteShader, L"Bridge", L"BridgeMaterial");
		sh::Material::Make_Material(spriteShader, L"GhostBox1", L"GhostBox1Material");
		sh::Material::Make_Material(spriteShader, L"GhostBox2", L"GhostBox2Material");

		sh::Material::Make_Material(debugShader, L"DebugMaterial");
	}

	void Initialize()
	{
		LoadMesh();
		LoadBuffer();
		LoadShader();
		SetupState();
		LoadMaterial();
	}

	void PushDebugMeshAttribute(DebugMesh mesh)
	{
		debugMeshs.push_back(mesh);
	}

	void Render()
	{
		for (CameraController* cam : cameras)
		{
			if (cam == nullptr)
				continue;

			cam->Render();
		}

		cameras.clear();
	}

	void Release()
	{
		for ( ConstantBuffer* buff : constantBuffer )
		{
			if (buff == nullptr)
				continue;

			delete buff;
			buff = nullptr;
		}
	}
}



