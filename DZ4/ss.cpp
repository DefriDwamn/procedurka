#include <stdexcept>
#include <iostream>
#include <string>

int toDecimal(std::string num, int base) {
  int digits = num.length(), sum = 0;

  for (size_t i = 0; i < digits; i++) {
    char curr = num[i];
    int currToInt;
    if (curr >= 'A' && curr <= 'Z') {
      curr = (int)(curr - 16) + 9;
      currToInt = curr - '0';
    } else if (curr >= '0' && curr <= '9') {
      currToInt = curr - '0';
    } else
      throw std::invalid_argument("Wrong Num");

    if (currToInt >= base) throw new std::invalid_argument("Wrong Num");

    sum += std::pow(base, digits - i - 1) * currToInt;
  }

  return sum;
}

std::string fromDecimal(int num, int base) {
  std::string tresult;
  if (num < base) {
    if (num >= 10 && num <= 36) {
      char n1, n2;
      n1 = char((num - 9) + 16 + '0');
      n2 = char(num + '0');
      if (n1 >= 'A' && n1 <= 'Z') {
        tresult += n1;
      } else
        tresult += n2;

      return tresult;
    } else
      return std::to_string(num);
  }

  for (; num > 0; num = num / base) {
    int ost = num % base;
    if (ost >= 10 && ost <= 36) {
      char n1, n2;
      n1 = char((ost - 9) + 16 + '0');
      n2 = char(ost + '0');
      if (n1 >= 'A' && n1 <= 'Z') {
        tresult += n1;
      } else
        tresult += n2;

    } else
      tresult += std::to_string(ost);
  }
  std::string result(tresult.rbegin(), tresult.rend());
  return result;
}

int main() {
  setlocale(0, "");
  std::string num;
  int base, tobase;

  while (1) {
    try {
      std::cout
          << "Введите: число | его систему счисления | систему перевода: ";
      std::cin >> num >> base >> tobase;
      int temp = toDecimal(num, base);
      if (tobase == 10)
        std::cout << temp << '\n';
      else {
        std::string fd = fromDecimal(temp, tobase);
        std::cout << fd << '\n';
      }
    } catch (std::exception& e) {
      std::cout << e.what() << '\n';
    }
  }
}