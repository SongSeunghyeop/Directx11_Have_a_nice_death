#include "shMaterial.h"

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
			mTexture->BindShader(eShaderStage::PS, 0);

		if (mShader)
			mShader->Binds();
	}

	void Material::Clear()
	{
		mTexture->Clear();
	}
	void Material::Make_Material(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, std::wstring Materialname)
	{
		std::shared_ptr<Material> mateiral = std::make_shared<Material>();
		mateiral->SetShader(shader);
		mateiral->SetTexture(texture);
		mateiral->SetRenderingMode(eRenderingMode::Transparent);
		Resources::Insert(Materialname, mateiral);
	}
}
