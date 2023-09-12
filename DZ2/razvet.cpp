#include <cmath>
#include <iostream>
#include <string>

int main() {
  double x, a;

  std::cout << "Введите x, a: ";
  std::cin >> x >> a;

  double absX = std::abs(x);

  if (absX < 1) {
    if (absX > 0) {
      std::cout << "w = " << a * std::log(absX) << '\n';
    } else {
      std::cout << "no solution\n";
    }
  } else {
    double s = a - (x * x);

    if (s >= 0)
      std::cout << "w = " << std::sqrt(s) << '\n';
    else
      std::cout << "no solution\n";
  }
}