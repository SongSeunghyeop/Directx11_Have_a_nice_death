#include "shRenderer.h"
#include "shTexture.h"
#include "shMaterial.h"

namespace renderer
{
	using namespace sh;
	using namespace sh::graphics;

	std::shared_ptr<Shader> spriteShader;

	Vertex vertexes[4] = {};
	sh::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};

	//
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End] = {};
	
	//
	std::vector<sh::CameraController*> cameras = {};
	std::shared_ptr<Shader> normalShader;

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

		normalShader = sh::Resources::Find<Shader>(L"TriangleShader");
		sh::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, normalShader->GetVSCode()
			, normalShader->GetInputLayoutAddressOf());

		normalShader = sh::Resources::Find<Shader>(L"SpriteShader");
		sh::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			, normalShader->GetVSCode()
			, normalShader->GetInputLayoutAddressOf());

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

	void LoadBuffer()
	{
		// Vertex Buffer
		//Mesh 클래스 객체 스마트포인터형 선언 및 생성
		std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();// Mesh 생성
		Resources::Insert(L"RectMesh", mesh); // 빈 Mesh

		mesh->CreateVertexBuffer(vertexes, 4); // 생성한 버텍스 정보 매쉬에 저장

		std::vector<UINT> indexes = {}; // 인덱스 버퍼
		indexes.push_back(0); // 순서 저장
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		constantBuffer[(UINT)eCBType::Transform] = new ConstantBuffer(eCBType::Transform); //상수 버퍼
		constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));
	}

	void LoadShader() // 쉐이더 생성
	{
		normalShader = std::make_shared<Shader>();
		normalShader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		normalShader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
		sh::Resources::Insert(L"TriangleShader", normalShader);

		spriteShader = std::make_shared<Shader>();
		spriteShader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		spriteShader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		sh::Resources::Insert(L"SpriteShader", spriteShader);
	}

	void LoadSprites()
	{
		std::shared_ptr<Texture> Player_texture
			= Resources::Load<Texture>(L"Player", L"..\\Resources\\Texture\\Death.png");

		std::shared_ptr<Texture> Lobby_texture
			= Resources::Load<Texture>(L"Lobby", L"..\\Resources\\Texture\\Lobby.png");

		std::shared_ptr<Texture> Office_texture
			= Resources::Load<Texture>(L"Office", L"..\\Resources\\Texture\\Office.png");

		std::shared_ptr<Texture> Title_texture
			= Resources::Load<Texture>(L"Title", L"..\\Resources\\Texture\\title.png");

		std::shared_ptr<Texture> Column_texture
			= Resources::Load<Texture>(L"Column", L"..\\Resources\\Texture\\Column.png");

		std::shared_ptr<Texture> BigRock_texture
			= Resources::Load<Texture>(L"Big_Rock", L"..\\Resources\\Texture\\Big_Rock.png");

		std::shared_ptr<Texture> Ground_texture
			= Resources::Load<Texture>(L"Ground", L"..\\Resources\\Texture\\Ground.png");

		std::shared_ptr<Texture> Tree_texture
			= Resources::Load<Texture>(L"Tree", L"..\\Resources\\Texture\\Tree.png");

		std::shared_ptr<Texture> Wall_texture
			= Resources::Load<Texture>(L"Wall", L"..\\Resources\\Texture\\Wall.png");

		std::shared_ptr<Texture> Pillar_texture
			= Resources::Load<Texture>(L"Pillar", L"..\\Resources\\Texture\\Pillar.png");

		std::shared_ptr<Texture> CircleStair_texture
			= Resources::Load<Texture>(L"CircleStair", L"..\\Resources\\Texture\\CircleStair.png");

		std::shared_ptr<Texture> BossChair_texture
			= Resources::Load<Texture>(L"BossChair", L"..\\Resources\\Texture\\BossChair.png");

		std::shared_ptr<Texture> BossDesk_texture
			= Resources::Load<Texture>(L"BossDesk", L"..\\Resources\\Texture\\BossDesk.png");

		std::shared_ptr<Texture> StairR_texture
			= Resources::Load<Texture>(L"Stair_R", L"..\\Resources\\Texture\\Stair_R.png");

		std::shared_ptr<Texture> SupportDesk_texture
			= Resources::Load<Texture>(L"SupportDesk", L"..\\Resources\\Texture\\SupportDesk.png");

		//메터리얼을 만들고 로드한 텍스쳐와 스프라이트 쉐이더를 세팅한다
		sh::Material::Make_Material(spriteShader, Player_texture, L"PlayerMaterial");
		sh::Material::Make_Material(spriteShader, Lobby_texture, L"LobbyMaterial");
		sh::Material::Make_Material(spriteShader, Office_texture, L"OfficeMaterial");
		sh::Material::Make_Material(spriteShader, Title_texture, L"TitleMaterial");
		sh::Material::Make_Material(spriteShader, Column_texture, L"ColumnMaterial");
		sh::Material::Make_Material(spriteShader, BigRock_texture, L"BigRockMaterial");
		sh::Material::Make_Material(spriteShader, Ground_texture, L"GroundMaterial");
		sh::Material::Make_Material(spriteShader, Tree_texture, L"TreeMaterial");
		sh::Material::Make_Material(spriteShader, Wall_texture, L"WallMaterial");
		sh::Material::Make_Material(spriteShader, Pillar_texture, L"PillarMaterial");
		sh::Material::Make_Material(spriteShader, CircleStair_texture, L"CircleStairMaterial");
		sh::Material::Make_Material(spriteShader, BossChair_texture, L"BossChairMaterial");
		sh::Material::Make_Material(spriteShader, BossDesk_texture, L"BossDeskMaterial");
		sh::Material::Make_Material(spriteShader, StairR_texture, L"StairR_Material");
		sh::Material::Make_Material(spriteShader, SupportDesk_texture, L"SupportDesk_Material");
	}

	void Initialize()
	{
		//정점 생성
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

		LoadBuffer();
		LoadShader();
		LoadSprites();
		SetupState();
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



