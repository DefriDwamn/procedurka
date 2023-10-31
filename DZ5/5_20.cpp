#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

std::map<std::wstring, std::wstring> phoneFields;

bool addPhoneField(std::wstring surname, std::wstring phoneNumber) {
  char first = *phoneNumber.begin();
  size_t len = phoneNumber.size();
  if (((first == '7' || first == '8') && len == 11) ||
      (first == '+' && len == 12)) {
    phoneFields[surname] = phoneNumber;
    return true;
  }
  return false;
}

bool inOnlyEven(std::wstring wst) {
  std::wstring evens{L"02468"};
  size_t plus = *wst.begin() == '+' ? 2 : 1;
  for (auto it = wst.begin() + plus; it != wst.end(); ++it) {
    if (evens.find(*it) == std::wstring::npos) return false;
  }
  return true;
}

void fillNumbersFile(std::string phoneFileName) {
  size_t maxSizeName = 0;
  for (const auto &[surname, number] : phoneFields) {
    maxSizeName = std::max(surname.size(), maxSizeName);
  }

  std::wofstream ofs(phoneFileName);
  ofs.imbue(std::locale("ru-RU.UTF-8"));

  ofs << L"Фамилия" << std::wstring(7, '\t') << L"Номер" << L'\n'
      << std::wstring(40, '-') << '\n';

  for (const auto &[surname, number] : phoneFields) {
    ofs << surname << std::wstring(maxSizeName - surname.size(), ' ')
        << std::wstring(5, '\t') << number << L'\n';
  }
  ofs.close();
}

void fillSortedFile(std::string fileName) {
  std::vector<std::pair<std::wstring, std::wstring>> sortedNumbers(
      phoneFields.begin(), phoneFields.end());
  std::sort(sortedNumbers.begin(), sortedNumbers.end(),
            [](const auto &p1, const auto &p2) {
              return std::tie(p2.second, p1.first) <
                     std::tie(p1.second, p2.first);
            });

  size_t maxSizeName = 0;
  for (const auto &[surname, number] : sortedNumbers) {
    maxSizeName = std::max(surname.size(), maxSizeName);
  }

  std::wofstream ofs(fileName);
  ofs.imbue(std::locale("ru-RU.UTF-8"));

  ofs << L"Отсортировнный список четных номеров\n\n"
      << L"Фамилия" << std::wstring(7, '\t') << L"Номер" << L'\n'
      << std::wstring(40, '-') << '\n';

  for (const auto &[surname, number] : sortedNumbers) {
    if (!inOnlyEven(number)) continue;
    ofs << surname << std::wstring(maxSizeName - surname.size(), ' ')
        << std::wstring(5, '\t') << number << L'\n';
  }
  ofs.close();
}

int main() {
  std::map<std::wstring, std::wstring> example{
      {L"Богомолов", L"89855259176"}, {L"Галкин", L"79855259556"},
      {L"Дегтярев", L"82466002244"},  {L"Долгов", L"+72866644002"},
      {L"Иванов", L"82466282244"},    {L"Смирнов", L"+79843247549"}};

  for (const auto &[ename, enumb] : example) addPhoneField(ename, enumb);

  fillNumbersFile("phone.txt");
  fillSortedFile("phoneEvens.txt");
}