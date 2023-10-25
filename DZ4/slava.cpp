#include <windows.h>
#include <iostream>

WINBOOL(*sct)
(HANDLE hConsoleOutput, WORD wAttributes){SetConsoleTextAttribute};

int main() {
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  sct(h, 0xFF);
  std::cout << std::string(30, ' ') << '\n';
  sct(h, 0x11);
  std::cout << std::string(30, ' ') << '\n';
  sct(h, 0x44);
  std::cout << std::string(30, ' ');
  sct(h, 0);
}