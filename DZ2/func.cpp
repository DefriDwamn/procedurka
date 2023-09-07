#include <cmath>
#include <iostream>
#include <string>

int main() {
  double x, y, b;

  std::cout << "Введите x, y, b: ";
  std::cin >> x >> y >> b;

  double n1 = b - y;
  double n2 = b - x;

  if ((n1 > 0) && (n2 >= 0)) {
    std::cout << "z = " << std::log(n1) * std::sqrt(n2) << '\n';
  } else {
    std::cout << "no solution\n";
  }
}