#include <iostream>
#include <string>

int main() {
  long long N;

  std::cout << "Введите N: ";
  std::cin >> N;

  for (int i = 1; i <= 10; ++i) {
    std::cout << i << " - " << N++ << '\n';
  }
}