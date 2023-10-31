#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

std::vector<int32_t> GenerateRandomInt32Vec(size_t& count) {
  if (count < 1) throw std::invalid_argument("Кол-во чисел < 1");

  std::random_device randd;
  std::mt19937_64 gen(randd());
  std::uniform_int_distribution<> distr(-2147483648, 2147483647);

  std::vector<int32_t> randoms;
  for (size_t i = 0; i != count; ++i) {
    randoms.push_back(distr(gen));
  }
  return randoms;
}

std::vector<int32_t> fillFileOfInt32(std::string name, size_t count) {
  std::ofstream ofs(name);
  std::vector<int32_t> vec = GenerateRandomInt32Vec(count);
  for (const auto& n : vec) ofs << n << '\n';
  ofs.close();
  return vec;
}

typedef std::vector<int32_t>::iterator vecIt;

void bubbleSort(vecIt first, vecIt last) {
  if (first == last) return;
  --last;
  if (first == last) return;
  bool swapped;
  do {
    swapped = false;
    auto current = first;
    while (current != last) {
      auto next = current;
      ++next;
      if (*next < *current) {
        std::iter_swap(current, next);
        swapped = true;
      }
      ++current;
    }
    --last;
  } while (swapped && first != last);
}

void copy(vecIt first, vecIt last, vecIt out) {
  for (; first != last; ++first, ++out) *out = *first;
}

void merge(vecIt first1, vecIt last1, vecIt first2, vecIt last2, vecIt out) {
  for (; first1 != last1; ++out) {
    // if vec2 is empty
    if (first2 == last2) copy(first1, last1, out);

    *out = (*first2 < *first1) ? *out = *(first2++) : *out = *(first1++);
  }
  copy(first2, last2, out);
}

int main() {
  size_t countA, countB;
  std::cout << "Введите сначала кол-во чисел в файлах A и B: ";
  std::cin >> countA >> countB;

  std::vector<int32_t> a = fillFileOfInt32("A.txt", countA);
  std::vector<int32_t> b = fillFileOfInt32("B.txt", countB);
  bubbleSort(a.begin(), a.end());
  bubbleSort(b.begin(), b.end());

  std::vector<int32_t> c(a.size() + b.size());
  merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
  std::ofstream ofs("C.txt");
  for (const auto& n : c) ofs << n << '\n';
  ofs.close();
}