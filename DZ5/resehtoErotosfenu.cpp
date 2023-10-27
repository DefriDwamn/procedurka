#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>
typedef size_t st;

std::vector<st> PrimeNumbers(st to) {
  std::vector<bool> nums(to, true);

  if (to < 2) throw std::invalid_argument("Неверный конец диапазона");
  st sqrtto = static_cast<st>(std::sqrt(to + 0.));
  for (st i = 2; i < sqrtto; ++i) {
    if (nums[i]) {
      for (st j = i * i; j <= to; j = j + i) nums[j] = false;
    }
  }
  std::vector<st> primes;
  for (st i = 0; i < to; ++i)
    if (nums[i]) primes.push_back(i);

  return primes;
}

int main() {
  st to;
  std::cout << "Введите числовой конец диапазона простых чисел: ";
  std::cin >> to;
  try {
    for (const auto &e : PrimeNumbers(to)) {
      std::cout << e << ' ';
    }
  } catch (std::exception &e) {
    std::cout << e.what();
  }
}