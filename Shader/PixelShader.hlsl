// ピクセルシェーダの実装
#include "ShaderCommon.hlsli"

// ピクセルシェーダのメインエントリーポイント
//PSOutput main(ColorVSOutput input)
//{
//    // 色データをそのまま代入するだけの処理
//    PSOutput output = (PSOutput) 0;
//    output.Color = input.Color;
//    return output;
//};

SamplerState ColorSmp : register(s0);
Texture2D ColorMap : register(t0);


// ピクセルシェーダのメインエントリーポイント
PSOutput main(VSOutput input)
{
    PSOutput output = (PSOutput) 0;

    output.Color = ColorMap.Sample(ColorSmp, input.TexCoord);

    return output;
}