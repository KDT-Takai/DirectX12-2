float4 main( float4 pos : POSITION ) : SV_POSITION
{
	return pos;
}
struct VSInput
{
    float3 Position : POSITION; // 位置座標
    float4 Color : COLOR; //  頂点カラー
};