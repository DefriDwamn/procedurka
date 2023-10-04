#include <cmath>
#include <iostream>
#include <vector>

int main() {
  double S, m0, n, psolve = -1;

  std::cout << "Введите S, m0, n: ";
  std::cin >> S >> m0 >> n;

  int left = 0, right = 100, mid, counter = 0;

  do {
    mid = (left + right) / 2;

    double r = mid / 100;
    double r1pow = std::pow(1 + r, n);
    double second = r1pow - 1;

    double m = ((S * r * r1pow) / (12 * second));
    double mabs = std::abs(m - m0);

    if (mabs < 0.001) {
      psolve = mid;
      break;
    } else if (m < m0)
      left = mid + 1;
    else
      right = mid - 1;

    ++counter;
  } while (left <= right);

  if (psolve == -1) {
    std::cout << "no solution" << '\n';
  } else {
    std::cout << "p = " << psolve << '\n' << "Кол-во итераций: " << counter;
  }
}