#include "GraphicsDevice.h"
#include "Renderer.h"

GraphicsDevice::GraphicsDevice(ID3D11Device* device, ID3D11DeviceContext* context)
    : m_device(device), m_context(context)
{
}

void GraphicsDevice::RenderFrame(Renderer* renderer, float angle)
{
    renderer->m_world = XMMatrixRotationY(angle);

    renderer->Render(m_context);
}
