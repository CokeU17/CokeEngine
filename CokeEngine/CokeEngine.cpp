#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "resource.h"

// Estructuras
struct SimpleVertex
{
    XMFLOAT3 Pos;
    XMFLOAT2 Tex;
};

struct CBNeverChanges
{
    XMMATRIX mView;
};

struct CBChangeOnResize
{
    XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
    XMMATRIX mWorld;
    XMFLOAT4 vMeshColor;
};

// Variables globales
HINSTANCE                           g_hInst = NULL;
HWND                                g_hWnd = NULL;
D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;
ID3D11Device* g_pd3dDevice = NULL;
ID3D11DeviceContext* g_pImmediateContext = NULL;
IDXGISwapChain* g_pSwapChain = NULL;
ID3D11RenderTargetView* g_pRenderTargetView = NULL;
ID3D11Texture2D* g_pDepthStencil = NULL;
ID3D11DepthStencilView* g_pDepthStencilView = NULL;
ID3D11VertexShader* g_pVertexShader = NULL;
ID3D11PixelShader* g_pPixelShader = NULL;
ID3D11InputLayout* g_pVertexLayout = NULL;
ID3D11Buffer* g_pVertexBuffer = NULL;
ID3D11Buffer* g_pIndexBuffer = NULL;
ID3D11Buffer* g_pCBNeverChanges = NULL;
ID3D11Buffer* g_pCBChangeOnResize = NULL;
ID3D11Buffer* g_pCBChangesEveryFrame = NULL;
ID3D11Buffer* g_pCBPointLight = NULL;
ID3D11ShaderResourceView* g_pTextureRV = NULL;
ID3D11SamplerState* g_pSamplerLinear = NULL;
XMMATRIX                            g_World;
XMMATRIX                            g_PlaneWorld;
XMMATRIX                            g_View;
XMMATRIX                            g_Projection;
XMFLOAT4                            g_vMeshColor(0.7f, 0.7f, 0.7f, 1.0f);

// Variables para plano y sombras
ID3D11Buffer* g_pPlaneVertexBuffer = NULL;
ID3D11Buffer* g_pPlaneIndexBuffer = NULL;
UINT                                g_planeIndexCount = 0;
ID3D11PixelShader* g_pShadowPixelShader = NULL;
ID3D11BlendState* g_pShadowBlendState = NULL;
ID3D11DepthStencilState* g_pShadowDepthStencilState = NULL;
XMFLOAT4                            g_LightPos(2.0f, 4.0f, -2.0f, 1.0f);

// Declaración de funciones
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void UpdateScene();
void RenderScene();
HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

// Aquí vienen las implementaciones (InitDevice, RenderScene, CleanupDevice...)

// No debe existir ninguna función wWinMain aquí.
// Este archivo es solo funcional, no el punto de entrada.