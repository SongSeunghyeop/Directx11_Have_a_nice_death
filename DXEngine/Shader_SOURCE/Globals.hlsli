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
    float3 pad;
}

cbuffer SetUV : register(b4)
{
    uint flipx;
}

cbuffer SetCOLOR : register(b5)
{
    float4 colorInfo;
    uint colorDown;
}

cbuffer ParticleSystem : register(b6)
{
    uint elementCount;
    float elapsedTime;
    int padd;
    int padd2;
}


Texture2D albedoTexture : register(t0);
Texture2D atlasTexture : register(t12);

struct LightAttribute
{
    float4 color;
    float4 position;
    float4 direction;
    
    uint type;
    float radius;
    float angle;
    int pad;
};

struct Particle
{
    float4 position;
    float4 direction;
    
    float endTime;
    float time;
    float speed;
    uint active;
};

StructuredBuffer<LightAttribute> lightsAttribute : register(t13);
StructuredBuffer<Particle> particles : register(t14);

SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);

void CalculateLight2D(in out float4 lightColor, float3 position, int idx)
{
    if (0 == lightsAttribute[idx].type)
    {
        lightColor += lightsAttribute[idx].color;
    }
    else if (1 == lightsAttribute[idx].type)
    {
        float length = distance(position.xy, lightsAttribute[idx].position.xy);
        
        if (length < lightsAttribute[idx].radius)
        {
            float ratio = 1.0f - (length / lightsAttribute[idx].radius);
            lightColor += lightsAttribute[idx].color * ratio;
        }
    }
    else if (2 == lightsAttribute[idx].type) // 스폿 조명 (타입 2)
    {
        float3 toLightDir = normalize(lightsAttribute[idx].position.xyz - position);
        float3 lightDir = normalize(float3(0.0, 1.0, 0.0)); // 오브젝트 아래 방향
        float spotAngleCos = cos(radians(lightsAttribute[idx].angle)); // 60도 각도 (cosine 값 사용)

    // 스포트라이트 각도에 따라 빛이 증폭되도록 함
        float spotFactor = dot(lightDir, toLightDir);
        
        if (spotFactor > spotAngleCos)
        {
            float length = distance(position.xy, lightsAttribute[idx].position.xy);
            float lengthX = distance(position.x, lightsAttribute[idx].position.x);
            
            if (length < lightsAttribute[idx].radius)
            {
                float ratio = 1.0f - (length / lightsAttribute[idx].radius);
                lightColor += lightsAttribute[idx].color * ratio;
            }
        }
    }

}