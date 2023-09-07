#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fs("file.txt", std::fstream::out);
  std::string s;

  fs << "Работа с файлами в С++";

  fs.close();

  fs.open("file.txt", std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "File are not opened\n";
    return 0;
  }
  while (getline(fs, s)) {
    std::cout << s << '\n';
  }
}