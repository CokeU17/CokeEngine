#pragma once

#include <d3d11.h>
#include <DirectXMath.h>

class GraphicsDevice {
public:
    GraphicsDevice(HWND hwnd);
    ~GraphicsDevice();

    ID3D11Device* GetDevice() const { return m_device; }
    ID3D11DeviceContext* GetContext() const { return m_context; }

    void ClearRenderTarget(float r, float g, float b, float a);
    void Present();

private:
    void CreateDeviceAndSwapChain(HWND hwnd);
    void CreateRenderTarget();

    ID3D11Device* m_device = nullptr;
    ID3D11DeviceContext* m_context = nullptr;
    IDXGISwapChain* m_swapChain = nullptr;
    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};
