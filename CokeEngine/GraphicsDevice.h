#pragma once
#include <d3d11.h>
#include "Renderer.h"

class GraphicsDevice
{
public:
    GraphicsDevice(ID3D11Device* device, ID3D11DeviceContext* context);

    void RenderFrame(Renderer* renderer, float angle);

private:
    ID3D11Device* m_device;
    ID3D11DeviceContext* m_context;
};
