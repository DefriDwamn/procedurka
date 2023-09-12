#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fs("file.txt", std::fstream::out);

  fs << "Abc1de\n123\naba42b52987523lk5ja6b\n78";

  fs.close();

  fs.open("file.txt", std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "File is not open\n";
    return 0;
  }

  char ch;
  bool prevNum = false;
  while (fs.get(ch)) {
    if (((ch - '0') <= 9) && ch != '\n') {
      std::cout << (prevNum ? '\0' : ' ') << ch;
      prevNum = true;
    } else {
      prevNum = false;
    }
  }
}