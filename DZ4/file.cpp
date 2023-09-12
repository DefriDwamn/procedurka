#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::fstream fs("file.txt", std::fstream::out);
  int num, sum = 0;

  std::cout << "Введите 10 чисел\n";
  for (short i = 0; i != 10; ++i) {
    std::cout << (i + 1) << ": ";
    std::cin >> num;
    fs << num << '\n';
  }
  fs.close();

  fs.open("file.txt", std::fstream::in);
  if (!fs.is_open()) {
    std::cout << "File is not open\n";
    return 0;
  }

  while (fs >> num) sum += num;
  std::cout << sum << '\n';
}