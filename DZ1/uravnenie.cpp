#include <iostream>
#include <string>

int main() {
  double b, c;

  std::cout << "Введите b, c: ";
  std::cin >> b >> c;

  if (b == 0)
    std::cout << (c == 0 ? "x: infinite nums of solutions\n" : "no solution\n");
  else
    std::cout << "x = " << ((-c) / b) << '\n';
}