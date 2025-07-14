#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

struct SimpleVertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};

class Renderer
{
public:
    Renderer(ID3D11Device* device, ID3D11DeviceContext* context);

    void Initialize();
    void Render();
    void CreateCubeBuffers();

    XMMATRIX m_world;
    XMMATRIX m_view;
    XMMATRIX m_projection;

private:
    ID3D11Device* device;
    ID3D11DeviceContext* context;

    ID3D11Buffer* vertexBuffer;
    ID3D11Buffer* indexBuffer;
    UINT indexCount;

    ID3D11VertexShader* m_vertexShader;
    ID3D11PixelShader* m_pixelShader;
    ID3D11InputLayout* m_inputLayout;
};
