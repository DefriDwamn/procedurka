#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
  std::fstream fs("file.txt", std::fstream::out);

  fs << "Abc1de\n12   3\naba42b52987523lk5ja6b\n78";

  fs.close();

  fs.open("file.txt", std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "File is not open\n";
    return 0;
  }
  std::string s;
  char ch;
  bool previousIsNum = false;
  while (fs.get(ch)) {
    if (isdigit(ch)) {
      if (!previousIsNum) {
        cout << "\n";
      }
      cout << ch;
      previousIsNum = true;
    } else {
      previousIsNum = false;
    }
  }
}
