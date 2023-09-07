#include <iostream>
#include <string>

int main() {
  double a, b;
  std::cin >> a >> b;
  std::cout << a + b << '\n' << a - b << '\n' << a * b << '\n';
  if (b != 0)
    std::cout << a / b << '\n';
  else
    std::cout << "no solution\n";
}