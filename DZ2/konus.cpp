#include <cmath>
#include <iostream>
#include <numbers>
#include <string>

int main() {
  double h, R, r, l;

  std::cout << "Введите h, R, r, l: ";
  std::cin >> h >> R >> r >> l;

  double hypo2 = h * h + (R - r) * (R - r);
  if (hypo2 < 0 || std::sqrt(hypo2) != l) {
    std::cout << "no solution\n";
    return 0;
  }

  std::cout << "V = "
            << (1 / 3.) * std::numbers::pi * h * ((R * R) + (R * r) + (r * r))
            << '\n';

  std::cout << "S = " << std::numbers::pi * ((R * R) + ((R + r) * l) + (r * r))
            << '\n';
}