#include "shMaterial.h"
#include "shRenderer.h"

namespace sh::graphics
{
	Material::Material()
		: Resource(sh::enums::eResourceType::Material)
		, mShader(nullptr)
		, mTexture(nullptr)
		, mMode(eRenderingMode::Opaque)
	{

	}

	Material::~Material()
	{

	}

	HRESULT Material::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Material::Binds()
	{
		if (mTexture)
			mTexture->BindShaderResource(eShaderStage::PS, 0);

		if (mShader)
			mShader->Binds();
	}

	void Material::Clear()
	{
		mTexture->Clear();
	}
	void Material::Make_Material(std::shared_ptr<Shader> shader,std::wstring textureName , std::wstring MaterialName)
	{
		std::shared_ptr<Material> material
			= std::make_shared<Material>();

		std::shared_ptr<Texture> texture
			= Resources::Load<Texture>(textureName, L"..\\Resources\\Texture\\" + textureName + L".png");

		material->SetShader(shader);
		material->SetTexture(texture);
		material->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(MaterialName, material);
	}

	void Material::Make_Material(std::shared_ptr<Shader>
		shader, std::wstring MaterialName)
	{
		std::shared_ptr<Material> material
			= std::make_shared<Material>();
		material->SetShader(shader);
		material->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(MaterialName, material);
	}
}
