#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

typedef std::invalid_argument invArg;

std::string GenerateRandomASCII(size_t &count) {
  if (count < 1) throw invArg("Кол-во символов < 1");

  std::random_device randd;
  std::mt19937_64 gen(randd());
  std::uniform_int_distribution<> distr(33, 126);  // from '!' to '~'

  std::string randoms;
  for (size_t i = 0; i != count; ++i) {
    randoms += static_cast<char>(distr(gen));
  }
  return randoms;
}

int main() {
  std::unordered_map<char, int> freqs;

  try {
    int type;
    std::cout
        << "Выберите режим:\n1.Вы уже создали file.txt и ввели свою строку из "
           "букв\n2.Вы хотите сгенерировать рандомную строку из букв\n";
    std::cin >> type;

    if (type == 2) {
      size_t countSymbols;
      std::cout << "Введите кол-во символов в файле: ";
      std::cin >> countSymbols;

      std::string symbols = GenerateRandomASCII(countSymbols);
      std::ofstream fs("file.txt");
      fs << symbols;
      fs.close();
    }

    std::ifstream fs("file.txt");
    char ch;
    while (fs >> ch) {
      ++freqs[ch];
    }
    fs.close();
  } catch (std::exception &e) {
    std::cout << e.what();
  }

  std::vector<std::pair<char, int>> sFreqs(freqs.begin(), freqs.end());

  std::sort(sFreqs.begin(), sFreqs.end(), [](const auto &p1, const auto &p2) {
    return std::tie(p1.second, p1.first) < std::tie(p2.second, p2.first);
  });

  int minFreq = (*sFreqs.begin()).second;

  std::cout << "Наименее часто встречающийся символ в файле:\n";
  for (const auto &[ch, fr] : sFreqs) {
    if (fr != minFreq) break;
    std::cout << ch << " - " << minFreq << '\n';
  }
}