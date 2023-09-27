#include <algorithm>
#include <iostream>
#include <string>

void bubbleSort(std::string::iterator first, std::string::iterator last) {
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

int main() {
  std::string s = "basdflzcytiybxxmfsdjxvkfsdaklf";
  bubbleSort(s.begin(), s.end());
  std::cout << s;
}