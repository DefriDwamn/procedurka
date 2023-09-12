#include <iostream>
#include <string>
#include <utility>

int main() {
  std::pair<std::string, bool> quests[3] = {
      {"На улице день? (1 - если да)", false},
      {"Шторы раздвинуты?", false},
      {"Лампа включена?", false}};

  for (auto& [quest, ans] : quests) {
    std::cout << quest << ' ';
    std::cin >> ans;
  }

  const bool& isMorning = quests[0].second;
  const bool& isShtori = quests[1].second;
  const bool& isLamp = quests[2].second;
  std::cout << ((isLamp || (isMorning && isShtori)) ? "В комнате светло\n"
                                                    : "В комнате не светло\n");
}