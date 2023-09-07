#include <iostream>
#include <numbers>
#include <string>

int main() {
  double h, R, r, l;

  std::cout << "Введите h, R, r, l: ";
  std::cin >> h >> R >> r >> l;

  if (h < 0 || R < 0 || r < 0) {
    std::cout << "V: no solution\n";
  } else {
    std::cout << "V = "
              << (1 / 3.) * std::numbers::pi * h * ((R * R) + (R * r) + (r * r))
              << '\n';
  }

  if (R < 0 || r < 0 || l < 0) {
    std::cout << "S: no solution\n";
  } else {
    std::cout << "S = "
              << std::numbers::pi * ((R * R) + ((R + r) * l) + (r * r)) << '\n';
  }
}