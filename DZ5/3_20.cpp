#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

typedef std::invalid_argument invArg;

char *GenerateRandomASCII(size_t &count)
{
    if (count < 1)
        throw invArg("Кол-во символов < 1");

    std::random_device randd;
    std::mt19937_64 gen(randd());
    std::uniform_int_distribution<> distr(33, 126); // from '!' to '~'

    char *randoms = new char[count];
    for (size_t i = 0; i != count; ++i)
    {
        randoms[i] = (char)distr(gen);
    }
    return randoms;
}

int main()
{
    std::unordered_map<char, int> freqs;
    size_t countSymbols;

    std::cout << "Введите кол-во символов в файле: ";
    std::cin >> countSymbols;

    try
    {
        char *symbols = GenerateRandomASCII(countSymbols);

        std::fstream fs("file.txt", std::fstream::out);
        for (size_t i = 0; i != countSymbols; ++i)
        {
            fs << symbols[i];
        }
        fs.close();

        fs.open("file.txt", std::fstream::in);
        char ch;
        while (fs >> ch)
        {
            ++freqs[ch];
        }
        fs.close();
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    std::vector<std::pair<char, int>> sFreqs(freqs.begin(), freqs.end());

    std::sort(sFreqs.begin(), sFreqs.end(), [](const auto &p1, const auto &p2)
              { return std::tie(p1.second, p1.first) < std::tie(p2.second, p2.first); });

    int minFreq = (*sFreqs.begin()).second;

    std::cout << "Наименее часто встречающийся символ в файле:\n";
    for (const auto &[ch, fr] : sFreqs)
    {
        if (fr != minFreq)
            break;
        std::cout << ch << " - " << minFreq << '\n';
    }
}