#include <bitset>
#include <cmath>
#include <iostream>

std::string* to4(std::bitset<32>* bs, size_t st) {
  std::string* s4 = new std::string[st];
  for (size_t i = 0; i != st; ++i) {
    std::string s;
    for (int j = 31; j > 0; j = j - 2) {
      int l = bs[i][j];
      int r = bs[i][j - 1];
      if (l && r)
        s += "3";
      else if (l && !r)
        s += "2";
      else if (!l && r)
        s += "1";
      else
        s += "0";
    }
    s4[i] = s;
  }
  return s4;
}

int main() {
  size_t n;
  std::cout << "Укажите n для диапазона [1:n]:";
  std::cin >> n;
  if (n < 1 || n > 4294967295) {
    std::cout << "Указан неверный диапазон!\n";
    return 0;
  }
  std::bitset<32>* bs = new std::bitset<32>[n + 1];
  for (size_t i = 0; i <= n; ++i) {
    bs[i] = i;
  }
  std::string* s4 = to4(bs, n + 1);
  for (size_t i = 0; i != n + 1; ++i) {
    std::cout << s4[i] << '\n';
  }
  delete[] bs;
}
