#pragma once
#include <Windows.h>

class Window
{
public:
    Window(HINSTANCE hInstance, int width, int height, const wchar_t* title);
    ~Window();

    bool ProcessMessages();
    HWND GetHWND() const;

private:
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    HINSTANCE m_hInstance;
    HWND m_hWnd;
    int m_width;
    int m_height;
    const wchar_t* m_title;
};
#pragma once
