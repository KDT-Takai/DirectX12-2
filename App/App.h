#pragma once
#include <Windows.h>
#include <cstdint>
#include <d3d12.h>
#include <dxgi1_4.h>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

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
    ID3D12Device* m_pDevice;
    // コマンドキュー
    ID3D12CommandQueue* m_pQueue;
    // スワップチェイン
	IDXGISwapChain3* m_pSwapChain;
    // カラーバッファ
	ID3D12Resource* m_pColorBuffer[FrameCount];
    // コマンドリスト
	ID3D12GraphicsCommandList* m_pCmdList;
    // ディスクリプタヒープ
    ID3D12DescriptorHeap* m_pHeapRTV;
    // フェンス
	ID3D12Fence* m_pFence;
    // フェンスイベント
    HANDLE m_FenceEvent;
    // フェンスカウント
	uint64_t m_FenceCount[FrameCount];
    // フレーム番号
	uint32_t m_FrameIndex;
    // CPUディスクリプタ
	D3D12_CPU_DESCRIPTOR_HANDLE m_HandleRTV[FrameCount];

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

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
};