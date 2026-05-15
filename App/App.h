#pragma once
#include <Windows.h>
#include <cstdint>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <wrl/client.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#include <cassert>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment( lib, "d3dcompiler.lib" )

#include "../Logger/Logger.hpp"

template <typename T>using ComPtr = Microsoft::WRL::ComPtr<T>;

struct alignas(256) Transform
{
    DirectX::XMMATRIX   World;      // ワールド行列
    DirectX::XMMATRIX   View;       // ビュー行列
    DirectX::XMMATRIX   Proj;       // 射影行列
};

template<typename T>
struct ConstantBufferView
{
    D3D12_CONSTANT_BUFFER_VIEW_DESC Desc;               // 定数バッファの構成設定
    D3D12_CPU_DESCRIPTOR_HANDLE     HandleCPU;          // CPUディスクリプタハンドル
    D3D12_GPU_DESCRIPTOR_HANDLE     HandleGPU;          // GPUディスクリプタハンドル
    T* pBuffer;            // バッファ先頭へのポインタ
};

class App
{
public:

    App(uint32_t width, uint32_t height);
    ~App();
    void Run();

private:

    static const uint32_t FrameCount = 2;
    // インスタンスハンドル
    HINSTANCE m_hInst;
    // ウィンドウハンドル
    HWND m_hWnd;
    // ウィンドウの横幅
    uint32_t m_Width;
    // ウィンドウの縦幅
    uint32_t m_Height;

    // デバイス
    ComPtr<ID3D12Device> m_pDevice;
    // コマンドキュー
    ComPtr<ID3D12CommandQueue> m_pQueue;
    // スワップチェイン
    ComPtr<IDXGISwapChain3> m_pSwapChain;
    // カラーバッファ
    ComPtr<ID3D12Resource> m_pColorBuffer[FrameCount];
    // コマンドアロケータ
    ComPtr<ID3D12CommandAllocator> m_pCmdAllocator[FrameCount];
    // コマンドリスト
    ComPtr<ID3D12GraphicsCommandList> m_pCmdList;
    // ディスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap> m_pHeapRTV;
    // フェンス
    ComPtr<ID3D12Fence> m_pFence;
    // ディスクリプタヒープ
    ComPtr<ID3D12DescriptorHeap> m_pHeapCBV;
    // 頂点バッファ
    ComPtr<ID3D12Resource> m_pVB;
    // インデックスバッファ
	ComPtr<ID3D12Resource> m_pIB;
    // 定数バッファ
    ComPtr<ID3D12Resource> m_pCB[FrameCount*2];
    // ルートシグニチャ
    ComPtr<ID3D12RootSignature> m_pRootSignature;
    // パイプラインステート
    ComPtr<ID3D12PipelineState> m_pPSO;
    // フェンスイベント
    HANDLE m_FenceEvent;
    // フェンスカウンター
	uint64_t m_FenceCounter[FrameCount];
    // フレーム番号
	uint32_t m_FrameIndex;
    // CPUディスクリプタ
	D3D12_CPU_DESCRIPTOR_HANDLE m_HandleRTV[FrameCount];
    // 頂点バッファビュー
    D3D12_VERTEX_BUFFER_VIEW m_VBV;
    // インデックスバッファビュー
    D3D12_INDEX_BUFFER_VIEW m_IBV;
    // ビューポート
    D3D12_VIEWPORT m_Viewport;
	// シザー矩形
    D3D12_RECT m_Scissor;
    // 定数バッファビュー
    ConstantBufferView<Transform> m_CBV[FrameCount*2];
    // 回転角
    float m_RotateAngle;

    bool InitApp();
    void TermApp();
    bool InitWnd();
    void TermWnd();
    void MainLoop();
    bool InitD3D();
    void TermD3D();
    void Render();
    void WaitGpu();
    void Present(uint32_t interval);
    bool OnInit();
    void OnTerm();

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
};