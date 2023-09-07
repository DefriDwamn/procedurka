#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
int main() {
  double x, a;
  std::cin >> x >> a;
  double absX = std::abs(x);
  if (absX < 1) {
    std::cout << a * std::log(absX) << '\n';
  } else {
    double s = a - (x * x);
    if (s >= 0)
      std::cout << sqrt(s) << '\n';
    else
      std::cout << "no solution\n";
  }
}