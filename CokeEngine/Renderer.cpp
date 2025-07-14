#include "Renderer.h"
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

void Renderer::CreateShaders()
{
    ID3DBlob* vsBlob = nullptr;
    ID3DBlob* psBlob = nullptr;

    HRESULT hr = D3DCompileFromFile(L"CokeEngine.fx", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "VS", "vs_4_0", 0, 0, &vsBlob, nullptr);
    if (FAILED(hr)) return;

    m_device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &m_vertexShader);

    hr = D3DCompileFromFile(L"CokeEngine.fx", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "PS", "ps_4_0", 0, 0, &psBlob, nullptr);
    if (FAILED(hr)) return;

    m_device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &m_pixelShader);

    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    UINT numElements = ARRAYSIZE(layout);

    m_device->CreateInputLayout(layout, numElements, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &m_inputLayout);

    vsBlob->Release();
    psBlob->Release();
}

void Renderer::Render(ID3D11DeviceContext* context, ID3D11Buffer* vertexBuffer, ID3D11Buffer* indexBuffer, UINT indexCount)
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