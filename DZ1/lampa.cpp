#include <iostream>
#include <string>

int main() {
  std::string ans;
  bool morning, shtor, lamp;
  std::cout << "На улице день? (yes - если да) ";
  std::cin >> ans;
  morning = (ans == "yes" ? true : false);

  std::cout << "Шторы раздвинуты? ";
  std::cin >> ans;
  shtor = (ans == "yes" ? true : false);

  std::cout << "Лампа включена? ";
  std::cin >> ans;
  lamp = (ans == "yes" ? true : false);

  std::cout << ((lamp || (morning && shtor)) ? "В комнате светло\n"
                                             : "В комнате не светло\n");
}