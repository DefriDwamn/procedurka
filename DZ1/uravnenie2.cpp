#include <cmath>
#include <iostream>
#include <string>

void linear(double& b, double& c) {
  if (b == 0)
    std::cout << (c == 0 ? "x: infinite nums of solutions\n" : "no solution\n");
  else
    std::cout << "x = " << ((-c) / b) << '\n';
}

void quadratic(double& a, double& b, double& c) {
  double D = (b * b) - (4 * a * c);

  if (D > 0) {
    double sqrtD = sqrt(D);
    std::cout << "x1 = " << ((-b) + sqrtD) / (2.0 * a) << '\n';
    std::cout << "x2 = " << ((-b) - sqrtD) / (2.0 * a) << '\n';
  } else if (D < 0) {
    std::cout << "no solution\n";
  } else {
    std::cout << "x = " << ((-b) / (2.0 * a)) << '\n';
  }
}

int main() {
  double a, b, c;

  std::cout << "Введите a, b, c: ";
  std::cin >> a >> b >> c;

  if (a == 0) {
    linear(b, c);
  } else {
    if (b == 0 && ((a > 0 && c > 0) || (a < 0 && c < 0))) {
      std::cout << "only complex nums solution\n";
    } else {
      quadratic(a, b, c);
    }
  }
}