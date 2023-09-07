#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fs("file.txt", std::fstream::out);

  fs << "Abc1de\n123\naba42blk5ja6b\n78";

  fs.close();

  fs.open("file.txt", std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "File is not open\n";
    return 0;
  }
  char ch;
  bool prevN = false;
  while (fs.get(ch)) {
    int n = ch - '0';
    if (n >= 0 && n <= 9) {
      std::cout << n << (prevN ? '-' : ' ');
      prevN = true;
    } else {
      prevN = false;
    }
  }
}