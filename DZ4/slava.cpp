#include <iostream>
#include <string>

int main() {
  for (int i = 0; i != 8; ++i) {
    for (int j = 0; j != 35; ++j) {
      std::cout << ((i < 4 && j < 8) ? '*' : '_');
    }
    std::cout << '\n';
  }
}