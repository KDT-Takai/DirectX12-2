#include "ShaderCommon.hlsli"

// 頂点シェーダのメインエントリーポイント
//VSOutput main(VSInput input)
//{
//    VSOutput output = (VSOutput) 0;
//    
//    // mulは4行4列の行列に右から4成分の列ベクトルを掛け算
//    float4 localPos = float4(input.Position, 1.0f);
//    float4 worldPos = mul(World, localPos);
//    float4 viewPos = mul(View, worldPos);
//    float4 projPos = mul(Proj, viewPos);
//
//    output.Position = projPos;
//    output.Color = input.Color;
//    
//    return output;
//}

// 頂点シェーダのメインエントリーポイント
VSOutput main(VSInput input)
{
    VSOutput output = (VSOutput) 0;

    float4 localPos = float4(input.Position, 1.0f);
    float4 worldPos = mul(World, localPos);
    float4 viewPos = mul(View, worldPos);
    float4 projPos = mul(Proj, viewPos);

    output.Position = projPos;
    output.TexCoord = input.TexCoord;

    return output;
}