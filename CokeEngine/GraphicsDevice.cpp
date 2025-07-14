#include "SimpleVertex.h"

void GraphicsDevice::CreateCubeBuffers()
{
    SimpleVertex vertices[] =
    {
        { XMFLOAT3(-1.0f, -1.0f, -1.0f), XMFLOAT4(1, 0, 0, 1) },
        { XMFLOAT3(-1.0f,  1.0f, -1.0f), XMFLOAT4(0, 1, 0, 1) },
        { XMFLOAT3(1.0f,   1.0f, -1.0f), XMFLOAT4(0, 0, 1, 1) },
        { XMFLOAT3(1.0f,  -1.0f, -1.0f), XMFLOAT4(1, 1, 0, 1) },
        { XMFLOAT3(-1.0f, -1.0f,  1.0f), XMFLOAT4(1, 0, 1, 1) },
        { XMFLOAT3(-1.0f,  1.0f,  1.0f), XMFLOAT4(0, 1, 1, 1) },
        { XMFLOAT3(1.0f,   1.0f,  1.0f), XMFLOAT4(1, 1, 1, 1) },
        { XMFLOAT3(1.0f,  -1.0f,  1.0f), XMFLOAT4(0, 0, 0, 1) },
    };

    unsigned short indices[] =
    {
        0,1,2, 0,2,3,
        4,6,5, 4,7,6,
        4,5,1, 4,1,0,
        3,2,6, 3,6,7,
        1,5,6, 1,6,2,
        4,0,3, 4,3,7
    };

    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(vertices);
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices;
    m_device->CreateBuffer(&bd, &initData, &m_vertexBuffer);

    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(indices);
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    initData.pSysMem = indices;
    m_device->CreateBuffer(&bd, &initData, &m_indexBuffer);

    m_indexCount = ARRAYSIZE(indices);
}
