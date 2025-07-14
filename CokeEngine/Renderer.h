#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class Renderer {
public:
    Renderer(ID3D11Device* device, ID3D11DeviceContext* context);

    void Initialize();
    void CreateCubeBuffers();
    void Render(ID3D11DeviceContext* context);

    void SetWorldMatrix(const XMMATRIX& matrix) { m_world = matrix; }
    void SetViewMatrix(const XMMATRIX& matrix) { m_view = matrix; }
    void SetProjectionMatrix(const XMMATRIX& matrix) { m_projection = matrix; }

private:
    ID3D11Device* device;
    ID3D11DeviceContext* context;

    ID3D11Buffer* vertexBuffer;
    ID3D11Buffer* indexBuffer;
    UINT indexCount;

    ID3D11VertexShader* m_vertexShader;
    ID3D11PixelShader* m_pixelShader;
    ID3D11InputLayout* m_inputLayout;

    XMMATRIX m_world;
    XMMATRIX m_view;
    XMMATRIX m_projection;
};
