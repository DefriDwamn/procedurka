#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int decode(std::string& s) {
  std::vector<int> num;
  int n;
  for (auto it = s.begin(); it != s.end(); ++it) {
    switch (*it) {
      case 'I':
        n = 1;
        break;
      case 'V':
        n = 5;
        break;
      case 'X':
        n = 10;
        break;
      case 'L':
        n = 50;
        break;
      case 'C':
        n = 100;
        break;
      case 'D':
        n = 500;
        break;
      case 'M':
        n = 1000;
        break;
    }
    num.push_back(n);
  }
  int d = num.back(), size = num.size() - 1;
  for (int i = 0; i < size; ++i)
    d += ((num[i] >= num[i + 1]) ? num[i] : -(num[i]));
  return d;
}

int main() {
  while (true) {
    std::string roman;
    std::cout << "Введите римское число: ";
    std::cin >> roman;
    std::cout << "Декодированное число: " << decode(roman) << '\n';
  }
}