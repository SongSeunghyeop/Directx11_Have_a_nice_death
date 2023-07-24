cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix WorldMatrix;
    row_major matrix ViewMatrix;
    row_major matrix ProjectionMatrix;
}
cbuffer SetUV : register(b2)
{
    float EndX;
    float EndY;
}

cbuffer Animator : register(b3)
{
    float2 SpriteLeftTop;
    float2 SpriteSize;
    float2 SpriteOffset;
    float2 AtlasSize;
    uint animationType;
}

cbuffer SetUV : register(b4)
{
    uint flipx;
}


Texture2D albedoTexture : register(t0);
Texture2D atlasTexture : register(t12);

SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);