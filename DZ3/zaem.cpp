#include <cmath>
#include <iostream>
int main() {
  double S, p, n;

  std::cout << "Введите S, p, n: ";
  std::cin >> S >> p >> n;

  double r = p / 100;
  double r1pow = std::pow(1 + r, n);
  double second = r1pow - 1;
  if (second == 0) {
    std::cout << "no solution" << '\n';
  } else {
    std::cout << "m = " << (S * r * r1pow) / (12 * second) << '\n';
  }
}