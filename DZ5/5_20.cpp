#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

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

  for (auto it = wst.begin() + 1; it != wst.end(); ++it) {
    if (*it == L'+') ++it;
    if (evens.find(*it) == std::wstring::npos) return false;
  }
  return true;
}

int main() {
  std::map<std::wstring, std::wstring> example{
      {L"Богомолов", L"89855259176"}, {L"Галкин", L"79855259556"},
      {L"Дегтярев", L"82466002244"},  {L"Долгов", L"+79852244321"},
      {L"Иванов", L"82466282244"},    {L"Смирнов", L"+79843247549"}};

  for (const auto &[ename, enumb] : example) addPhoneField(ename, enumb);

  size_t maxSizeName = 0;
  for (const auto &[surname, number] : phoneFields) {
    maxSizeName = std::max(surname.size(), maxSizeName);
  }

  std::wofstream ofs("phone.txt");
  ofs.imbue(std::locale("ru-RU.UTF-8"));

  ofs << L"Фамилия" << std::wstring(7, '\t') << L"Номер" << L'\n'
      << std::wstring(40, '-') << '\n';

  for (const auto &[surname, number] : phoneFields) {
    if (inOnlyEven(number)) {
      ofs << surname << std::wstring(maxSizeName - surname.size(), ' ')
          << std::wstring(5, '\t') << number << L'\n';
    }
  }
}