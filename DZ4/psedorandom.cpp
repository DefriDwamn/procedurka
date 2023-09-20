#include <cmath>
#include <iostream>
typedef long long ll;

ll random(ll& n, ll m, ll b, ll c) {
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    s = (m * s + b) % c;
  }
  return s;
}

int main() {
  while (true) {
    int var;
    ll n;
    std::cout << "Укажите номер варината(1 или 2): ";
    std::cin >> var;
    std::cout << "Ук1ажите число положительное число: ";
    std::cin >> n;
    std::cout << "Рандомное число = "
              << (var == 1 ? random(n, 37, 3, 64)
                           : random(n, 25173, 13849, 65537))
              << '\n';
  }
}
