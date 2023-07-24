#include "Globals.hlsli"

struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


float4 main(VSOut In) : SV_TARGET
{
    float4 color = (float4) 0.0f;
    
    color = albedoTexture.Sample(pointSampler, In.UV);
    
    if (animationType == 1)
    {
        float2 UV = (SpriteLeftTop / AtlasSize + SpriteOffset / AtlasSize) + (SpriteSize / AtlasSize * In.UV);
   
        if (flipx == -1)
        {
            UV.x *= -1;
            color = atlasTexture.Sample(pointSampler, UV);
        }
        else
        {
            color = atlasTexture.Sample(pointSampler, UV); 
        }
        
    }
    
    return color;

}