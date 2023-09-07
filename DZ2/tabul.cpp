#include <iostream>
#include <string>

int main() {
  std::cout << "x\ty\n";
  for (float x = -4; x <= 4; x = x + 0.5) {
    std::cout << x << '\t';
    if (x == 1)
      std::cout << "no solution" << '\n';
    else
      std::cout << (x * x - 2 * x + 2) / (x - 1) << '\n';
  }
}