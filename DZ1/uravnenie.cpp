#include <iostream>
#include <string>

int main() {
  double b, c;

  std::cin >> b >> c;

  if (b == 0)
    std::cout << (c == 0 ? "x = 0\n" : "no solution\n");
  else
    std::cout << "x = " << ((-c) / b) << '\n';
}