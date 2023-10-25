#include <windows.h>

#include <cmath>
#include <iostream>

int main() {
  HWND hWnd = GetConsoleWindow();
  HDC hDC = GetDC(hWnd);
  HPEN Pen = CreatePen(0, 2, RGB(25, 205, 95));
  SelectObject(hDC, Pen);
  MoveToEx(hDC, 350, 300, NULL);
  LineTo(hDC, 850, 300);
  MoveToEx(hDC, 600, 100, NULL);
  LineTo(hDC, 600, 500);
  Pen = CreatePen(0, 2, RGB(0, 0, 255));
  SelectObject(hDC, Pen);
  for (float x = -8.0f; x <= 8.0f; x += 0.01f) {
    MoveToEx(hDC, 50 * x + 600, -20 * std::sin(x) + 300, NULL);
    LineTo(hDC, 50 * x + 600, -20 * std::sin(x) + 300);
  }
  ReleaseDC(hWnd, hDC);
  std::cin.get();
}