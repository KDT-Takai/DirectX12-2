// ピクセルシェーダの実装
#include "ShaderCommon.hlsli"

struct PSOutput
{
    float4 Color : SV_TARGET0;  // ピクセルカラー
};

// ピクセルシェーダのメインエントリーポイント
PSOutput main(VSOutput input)
{
    // 色データをそのまま代入するだけの処理
    PSOutput output = (PSOutput) 0;
    output.Color = input.Color;
    return output;
};