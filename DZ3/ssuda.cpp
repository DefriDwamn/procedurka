#include <float.h>

#include <cmath>
#include <iostream>

int main() {
  double S, m0, n, minmabs = DBL_MAX, psolve = -1;

  std::cout << "Введите S, m0, n: ";
  std::cin >> S >> m0 >> n;

  for (double p = 1; p <= 100; ++p) {
    double r = p / 100;
    double r1pow = std::pow(1 + r, n);
    double second = r1pow - 1;

    if (second != 0) {
      double mabs = std::abs(((S * r * r1pow) / (12 * second)) - m0);
      if (mabs < 1 && mabs < minmabs) {
        minmabs = mabs;
        psolve = p;
      }
    }
  }

  if (psolve == -1) {
    std::cout << "no solution" << '\n';
  } else {
    std::cout << "p = " << psolve << '\n';
  }
}