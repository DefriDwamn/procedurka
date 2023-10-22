#include <conio.h>
#include <windows.h>

#include <cmath>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
  const wchar_t CLASS_NAME[] = L"Sinusoid Window Class";

  WNDCLASS wc = {};

  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd =
      CreateWindowEx(0,                     // Optional window styles.
                     CLASS_NAME,            // Window class
                     L"Sinusioid display",  // Window text
                     WS_OVERLAPPEDWINDOW,   // Window style

                     // Size and position
                     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

                     NULL,       // Parent window
                     NULL,       // Menu
                     hInstance,  // Instance handle
                     NULL        // Additional application data
      );

  if (hwnd == NULL) {
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0) > 0) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);

      FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW));

      EndPaint(hwnd, &ps);

      HDC hdc = GetDC(hwnd);
      HPEN pen = CreatePen(0, 2, RGB(255, 255, 255));
      SelectObject(hdc, pen);
      MoveToEx(hdc, 0, 85, NULL);
      LineTo(hdc, 200, 85);
      MoveToEx(hdc, 100, 0, NULL);
      LineTo(hdc, 100, 170);
      for (float x = -8.0f; x <= 8.0f; x += 0.01f) {
        MoveToEx(hdc, 10 * x + 100, -10 * std::sin(x) + 85, NULL);
        LineTo(hdc, 10 * x + 100, -10 * std::sin(x) + 85);
      }
      ReleaseDC(hwnd, hdc);
    }
      return 0;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}