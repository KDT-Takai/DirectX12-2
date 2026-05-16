#pragma once
#include <string>
#include <Shlwapi.h>

#pragma comment(lib, "Shlwapi.lib")

#include "../Logger/Logger.hpp"

bool SearchFilePath(const wchar_t* filename, std::wstring& result);

// memo
// 使い方
//std::wstring vsPath;
//std::wstring psPath;
//
//if (!SearchFilePath(L"VertexShader.cso", vsPath))
//{ return false; }
//
//if (!SearchFilePath(L"PixelShader.cso", psPath))
//{ return false; }
// 頂点シェーダ読み込み
//auto hr = D3DReadFileToBlob( vsPath.c_str(),pVSBlob.GetAddressOf());
//if (FAILED(hr))
//{ return false; }
// ピクセルシェーダ読み込み
//hr = D3DReadFileToBlob(psPath.c_str(), pPSBlob.GetAddressOf());
//if (FAILED(hr))
//{ return false; }
