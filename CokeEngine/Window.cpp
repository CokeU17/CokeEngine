#include "Window.h"

Window::Window(HINSTANCE hInstance, int width, int height, const wchar_t* title)
    : m_hInstance(hInstance), m_width(width), m_height(height), m_title(title)
{
    // Configuración de la ventana (igual que el profe)
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = m_hInstance;
    wc.lpszClassName = L"CokeWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassEx(&wc);

    m_hWnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        m_title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        m_width, m_height,
        nullptr, nullptr,
        m_hInstance,
        nullptr
    );

    ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window()
{
    DestroyWindow(m_hWnd);
}

bool Window::ProcessMessages()
{
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return false;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

HWND Window::GetHWND() const
{
    return m_hWnd;
}

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
