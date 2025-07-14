#include "Renderer.h"

Renderer::Renderer(ID3D11Device* device, ID3D11DeviceContext* context)
{
    this->device = device;
    this->context = context;

    vertexBuffer = nullptr;
    indexBuffer = nullptr;
    indexCount = 0;

    m_vertexShader = nullptr;
    m_pixelShader = nullptr;
    m_inputLayout = nullptr;

    m_world = XMMatrixIdentity();
    m_view = XMMatrixIdentity();
    m_projection = XMMatrixIdentity();
}

void Renderer::Initialize()
{
    CreateCubeBuffers();
}

void Renderer::CreateCubeBuffers()
{
    SimpleVertex vertices[] =
    {
        { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT4(1, 0, 0, 1) },
        { XMFLOAT3(-1.0f, +1.0f, -1.0f), XMFLOAT4(0, 1, 0, 1) },
        { XMFLOAT3(+1.0f, +1.0f, -1.0f), XMFLOAT4(0, 0, 1, 1) },
        { XMFLOAT3(+1.0f, -1.0f, -1.0f), XMFLOAT4(1, 1, 0, 1) },

        { XMFLOAT3(-1.0f, -1.0f, +1.0f), XMFLOAT4(1, 0, 1, 1) },
        { XMFLOAT3(-1.0f, +1.0f, +1.0f), XMFLOAT4(0, 1, 1, 1) },
        { XMFLOAT3(+1.0f, +1.0f, +1.0f), XMFLOAT4(1, 1, 1, 1) },
        { XMFLOAT3(+1.0f, -1.0f, +1.0f), XMFLOAT4(0, 0, 0, 1) },
    };

    unsigned short indices[] =
    {
        0,1,2, 0,2,3,    4,6,5, 4,7,6,
        4,5,1, 4,1,0,    3,2,6, 3,6,7,
        1,5,6, 1,6,2,    4,0,3, 4,3,7
    };

    indexCount = ARRAYSIZE(indices);

    // Crear Vertex Buffer
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(vertices);
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices;

    device->CreateBuffer(&bd, &initData, &vertexBuffer);

    // Crear Index Buffer
    bd.ByteWidth = sizeof(indices);
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    initData.pSysMem = indices;

    device->CreateBuffer(&bd, &initData, &indexBuffer);
}

void Renderer::Render()
{
    UINT stride = sizeof(SimpleVertex);
    UINT offset = 0;

    context->IASetInputLayout(m_inputLayout);
    context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R16_UINT, 0);
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    context->VSSetShader(m_vertexShader, nullptr, 0);
    context->PSSetShader(m_pixelShader, nullptr, 0);

    context->DrawIndexed(indexCount, 0, 0);
}
