#include <cmath>
#include <iostream>
typedef long long ll;

ll minusGCD(ll a, ll b) {
  ll c = std::max(a, b);
  a -= b - c;
  while (a != c) {
    if (c > a)
      c -= a;
    else
      a -= c;
  }
  return a;
}

ll divGCD(ll a, ll b) {
  ll c = std::max(a, b);
  a -= b - c;
  while (a * c != 0) {
    if (c > a)
      c %= a;
    else
      a %= c;
  }
  return a;
}
int main() {
  ll a, b;
  std::cout << "Введите два числа: ";
  std::cin >> a >> b;
  if (a != 0 && b != 0) {
    std::cout << "НОД делением: " << minusGCD(a, b) << '\n';
    std::cout << "НОД вычитанием: " << divGCD(a, b) << '\n';
  }
}
