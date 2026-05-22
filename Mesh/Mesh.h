#pragma once
#include <d3d12.h>
#include <DirectXMath.h>
#include <string>
#include <vector>

struct MeshVertex
{
	DirectX::XMFLOAT3 Position;
	DirectX::XMFLOAT3 Normal;
	DirectX::XMFLOAT2 TexCoord;
	DirectX::XMFLOAT3 Tangent;

	MeshVertex() = default;

	MeshVertex(
		DirectX::XMFLOAT3 const& Position,
		DirectX::XMFLOAT3 const& Normal,
		DirectX::XMFLOAT2 const& TexCoord,
		DirectX::XMFLOAT3 const& Tangent)
		: Position(Position)
		, Normal(Normal)
		, TexCoord(TexCoord)
		, Tangent(Tangent)
	{}

	static const D3D12_INPUT_LAYOUT_DESC InputLayout;

private:
	static const int InputElementCount = 4; 
	static const D3D12_INPUT_ELEMENT_DESC InputElements[InputElementCount];
};

struct Material
{
	DirectX::XMFLOAT3 Diffuse;
	DirectX::XMFLOAT3 Specular;
	float Alpha;
	float Shininess;
	std::string DiffuseMap;
};

struct Mesh
{
	std::vector<MeshVertex> Vertices;	// 頂点データ
	std::vector<uint32_t> Indices;		// 頂点インデックス
	uint32_t MaterialId;				// マテリアルID
};

bool LoadMesh(
	const wchar_t* filename,
	std::vector<Mesh>& meshes,
	std::vector<Material>& materials);