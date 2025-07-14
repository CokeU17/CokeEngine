#include "Renderer.h"
#include "SimpleVertex.h"  // Asegúrate que esta estructura esté definida correctamente.

Renderer::Renderer(ID3D11Device* device, ID3D11DeviceContext* context)
    : device(device), context(context),
    vertexBuffer(nullptr), indexBuffer(nullptr), indexCount(0),
    m_vertexShader(nullptr), m_pixelShader(nullptr), m_inputLayout(nullptr),
    m_world(XMMatrixIdentity()), m_view(XMMatrixIdentity()), m_projection(XMMatrixIdentity())
{
}

void Renderer::Initialize() {
    CreateCubeBuffers();
}

void Renderer::CreateCubeBuffers() {
    // Aquí defines vertices e índices (puedes reutilizar lo que ya tengas)
}

void Renderer::Render(ID3D11DeviceContext* context) {
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
