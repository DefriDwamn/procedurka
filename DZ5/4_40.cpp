#include <iostream>
#include <vector>
// 1 3 2 1 3 3 3 3 1 4 5 3 2 - [3 2 1]+[3 1 4]+[5 3 2] = 3
size_t countDecrSeq(std::vector<int>& seq) {
  size_t count = 0;
  size_t c = 0, prevC;
  if (seq.size() < 2) return 0;
  for (auto it = ++seq.begin(); it != seq.end(); ++it) {
    prevC = c;
    if (*it < *(it - 1))
      ++c;
    else
      c = 0;
    if ((c != prevC) && c == 0) ++count;
  }
  if (c != 0) ++count;
  return count;
}

int main() {
  std::cout << "Введите последовательность\n:";
  std::vector<int> seq;
  int n;
  while (std::cin >> n) {
    seq.push_back(n);
  }
  std::cout << "Кол-во уб. послед.: " << countDecrSeq(vec);
}