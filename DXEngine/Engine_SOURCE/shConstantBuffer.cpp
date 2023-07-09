#include "shConstantBuffer.h"
#include "shGraphicDevice_Dx11.h"

namespace sh::graphics
{
	ConstantBuffer::ConstantBuffer(const eCBType type)
		: GpuBuffer()
		, mType(type)
	{

	}

	ConstantBuffer::~ConstantBuffer()
	{
	}

	bool ConstantBuffer::Create(size_t size)
	{
		desc.ByteWidth = size;
		desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		desc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		sh::graphics::GetDevice()->CreateBuffer(buffer.GetAddressOf(), &desc, nullptr);

		return false;
	}

	void ConstantBuffer::SetData(void* data)
	{
		sh::graphics::GetDevice()->SetConstantBuffer(buffer.Get(), data, desc.ByteWidth);
	}

	void ConstantBuffer::Bind(eShaderStage stage)
	{
		sh::graphics::GetDevice()->BindConstantBuffer(stage, mType, buffer.Get());
	}

}
