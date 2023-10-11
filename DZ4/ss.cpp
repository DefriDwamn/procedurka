#include <iostream>
#include <string>

int toDecimal(std::string num, int base) {
  int digits = 0, sum = 0;

  digits = num.length();

  for (size_t i = 0; i < digits; i++) {
    char curr = num[i];
    if (curr >= 'A' && curr <= 'F') {
      curr = (int)(curr - 16) + 9;
    } else if (curr >= 'a' && curr <= 'f') {
      curr = (int)(curr - 48) + 9;
    }
    int currToInt = curr - '0';
    sum += std::pow(base, digits - i - 1) * currToInt;
  }

  return sum;
}

std:::string fromDecimal(int num, int base) {
  std::string digits;
  for (; num > 0; num = num / 2) {
    
  }
  return res;
}

int main() {
  std::string num;
  int base, tobase;
  std::cout << "Введите: число | его систему счисления | систему перевода: ";
  std::cin >> num >> base >> tobase;
  int temp = toDecimal(num, base);
  if (tobase == 10)
    std::cout << temp;
  else
    std::cout << fromDecimal(temp, tobase);
}