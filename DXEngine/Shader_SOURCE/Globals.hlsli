cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix WorldMatrix;
    row_major matrix ViewMatrix;
    row_major matrix ProjectionMatrix;
}

Texture2D albedoTexture : register(t0);

SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);