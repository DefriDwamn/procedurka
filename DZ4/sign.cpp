#include <iostream>
#include <string>

enum sign { minus = -1, null, plus };

sign signNum(const int& n) {
  return (n < 0 ? sign::minus : (n > 0 ? sign::plus : sign::null));
}

int main() {
  int n;
  std::cout << "Введите число: ";
  std::cin >> n;
  switch (signNum(n)) {
    case sign::plus:
      std::cout << "Число положительное\n";
      break;
    case sign::minus:
      std::cout << "Число отрицательное\n";
      break;
    default:
      std::cout << "Число равно нулю\n";
      break;
  }
}
