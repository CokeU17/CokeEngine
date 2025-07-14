#include "Window.h"
#include "GraphicsDevice.h"
#include "Renderer.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int)
{
    // Crear ventana
    Window window(hInstance, 1280, 720, L"CokeEngine - Ventana Principal");

    // Iniciar dispositivo gráfico
    GraphicsDevice graphics(window.GetHWND());

    // Crear renderer y shaders
    Renderer renderer(graphics.GetDevice());
    renderer.CreateShaders();
    renderer.CreateCubeBuffers();  // IMPORTANTE: No olvides llamar aquí

    bool running = true;
    while (running)
    {
        running = window.ProcessMessages();

        graphics.ClearRenderTarget(0.2f, 0.4f, 0.9f, 1.0f);

        renderer.Render(graphics.GetContext());  // Dibuja aquí el cubo

        graphics.Present();
    }

    renderer.Cleanup();
    return 0;
}
