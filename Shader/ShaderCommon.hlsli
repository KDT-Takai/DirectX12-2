// 定数バッファ
cbuffer Transform : register(b0)
{
    // float4x4は4行4列の16個の行列データ型
    float4x4 World : packoffset(c0); // ワールド行列
    float4x4 View : packoffset(c4); // ビュー行列
    float4x4 Proj : packoffset(c8); // 射影行列
}

// 頂点シェーダーの入力構造体
//struct VSInput
//{
//    float3 Position : POSITION; // 位置座標
//    float4 Color : COLOR; // 頂点カラー
//};

// 頂点シェーダーの出力構造体
//struct VSOutput
//{
//    float4 Position : SV_Position; // 位置座標
//    float4 Color : COLOR; // 頂点カラー
//};

// テクスチャを使用する頂点シェーダーの入力構造体
struct VSInput
{
    float3 Position : POSITION; // 位置座標
    float2 TexCoord : TEXCOORD0; // テクスチャ座標
};

// テクスチャを使用する頂点シェーダーの出力構造体
struct VSOutput
{
    float4 Position : SV_Position; // 位置座標
    float2 TexCoord : TEXCOORD0; // テクスチャ座標
};

struct PSOutput
{
    float4 Color : SV_TARGET0; // ピクセルカラー
};