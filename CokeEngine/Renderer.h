#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "SimpleVertex.h"

using namespace DirectX;

class Renderer
{
public:
    Renderer(ID3D11Device* device)
        : m_device(device), m_vertexShader(nullptr), m_pixelShader(nullptr),
        m_inputLayout(nullptr)
    {
    }

    void CreateShaders();
    void Render(ID3D11DeviceContext* context, ID3D11Buffer* vertexBuffer, ID3D11Buffer* indexBuffer, UINT indexCount);

private:
    ID3D11Device* m_device;
    ID3D11VertexShader* m_vertexShader;
    ID3D11PixelShader* m_pixelShader;
    ID3D11InputLayout* m_inputLayout;
};
