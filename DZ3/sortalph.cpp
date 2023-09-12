#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string s = "basdflzcytiybxxmfsdjxvkfsdaklf";
  std::sort(s.begin(), s.end());
  std::cout << s;
}