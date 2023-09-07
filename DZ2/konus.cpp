#include <iostream>
#include <numbers>
#include <string>
int main() {
  double h, R, r, l;
  std::cout << "Введите h, R, r, l: ";
  std::cin >> h >> R >> r >> l;
  std::cout << "V = "
            << (1 / 3.) * std::numbers::pi * h * ((R * R) + (R * r) + (r * r))
            << '\n';
  std::cout << "S = " << std::numbers::pi * ((R * R) + ((R + r) * l) + (r * r))
            << '\n';
}