#pragma once
#include "shComputeShader.h"
#include "shStructedBuffer.h"

namespace sh::graphics
{
	class ParticleShader : public ComputeShader
	{
	public:
		ParticleShader();
		~ParticleShader();

		virtual void Binds() override;
		virtual void Clear() override;

		void SetParticleBuffer(StructedBuffer* particleBuffer);

	private:
		StructedBuffer* mParticleBuffer;

	};
}
