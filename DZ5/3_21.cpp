#include <algorithm>
#include <fstream>
#include <iostream>
#include <locale>
#include <random>
#include <string>
#include <unordered_map>

wchar_t* GenerateRandomLetter(size_t& count) {
  if (count < 1) throw(L"Кол-во символов < 1");

  std::random_device randd;
  std::mt19937_64 gen(randd());

  std::uniform_int_distribution<> distrLetters;

  wchar_t* randoms = new wchar_t[count];
  for (size_t i = 0; i != count; ++i) {
    // random type of letter
    std::uniform_int_distribution<> distrType(0, 3);
    switch (distrType(gen)) {
      case 1:
        distrLetters =
            std::uniform_int_distribution<>(97, 122);  // from 'a' to 'z'
        break;
      case 2:
        distrLetters =
            std::uniform_int_distribution<>(1040, 1071);  // from 'А' to 'Я'
        break;
      case 3:
        distrLetters =
            std::uniform_int_distribution<>(1072, 1103);  // from 'а' to 'я'
        break;
      default:
        distrLetters =
            std::uniform_int_distribution<>(65, 90);  // from 'A' to 'Z'
        break;
    }

    randoms[i] = (wchar_t)distrLetters(gen);
  }
  return randoms;
}

bool findWchar(const wchar_t* arr, size_t& size, wchar_t toFind) {
  for (size_t i = 0; i != size; ++i) {
    if (arr[i] == toFind) return true;
  }
  return false;
}
int main() {
  // for clang compiler use this:
  //std::wcout.imbue(std::locale("ru-RU.UTF-8"));
  //std::wcin.imbue(std::locale("ru-RU.UTF-8"));

  // for msvc compiler use this:
  setlocale(0, "");

  size_t countSymbols;
  std::unordered_map<wchar_t, int> freqs;
  size_t glsSize = 33;
  const wchar_t* gls{L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY"};

  try {
    int type;
    std::wcout
        << L"Выберите режим:\n1.Вы уже создали file.txt и ввели свою строку из "
           L"букв\n2.Вы хотите сгенерировать рандомную строку из букв\n";
    std::wcin >> type;
    if (type == 2) {
      // ! : use only wcout or cout(wcin cin) in program
      std::wcout << L"Введите кол-во символов в файле: ";
      std::wcin >> countSymbols;

      wchar_t* symbols = GenerateRandomLetter(countSymbols);

      std::wfstream fs("file.txt", std::wfstream::out);
      fs.imbue(std::locale("ru-RU.UTF-8"));
      for (size_t i = 0; i != countSymbols; ++i) {
        fs << symbols[i];
      }
      fs.close();
    }

    std::wfstream fs("file.txt", std::wfstream::in);
    fs.imbue(std::locale("ru-RU.UTF-8"));
    wchar_t ch;
    while (fs >> ch) {
      if (findWchar(gls, glsSize, ch)) ++freqs[ch];
    }
    fs.close();
  } catch (wchar_t const* e) {
    std::wcout << e;
  }

  std::vector<std::pair<wchar_t, int>> sFreqs(freqs.begin(), freqs.end());

  std::sort(sFreqs.begin(), sFreqs.end(), [](const auto& p1, const auto& p2) {
    return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
  });

  int maxFreq = (*sFreqs.begin()).second;

  std::wcout << L"Наиболее часто встречающаяся глассная буква в файле:\n";
  for (const auto& [ch, fr] : sFreqs) {
    if (fr != maxFreq) break;
    std::wcout << ch << " - " << maxFreq << '\n';
  }
}