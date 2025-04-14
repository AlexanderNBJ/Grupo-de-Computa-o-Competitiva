/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>

int main()
{
    int n;
    while (std::cin >> n && n != 0)
    {
        std::cin.ignore();

        std::string textoConcatenado;
        for (int i = 0; i < n; ++i)
        {
            std::string linha;
            std::getline(std::cin, linha);
            textoConcatenado += linha;
        }

        std::unordered_map<std::string, int> digrafosMap;
        int totalDigrafos = 0;

        for (int i = 0; i < textoConcatenado.size() - 1; ++i)
        {
            std::string digrafo = textoConcatenado.substr(i, 2);
            digrafosMap[digrafo]++;
            totalDigrafos++;
        }

        std::vector<std::pair<std::string, int>> digrafosVet(digrafosMap.begin(), digrafosMap.end());

        std::sort(digrafosVet.begin(), digrafosVet.end(), [](const auto &a, const auto &b)
                  {
                      if (a.second == b.second)
                          return a.first < b.first;
                      return a.second > b.second; });

        for (int i = 0; i < 5; i++)
        {
            std::cout << digrafosVet[i].first << " " << digrafosVet[i].second << " " << std::fixed << std::setprecision(6) << static_cast<float>(digrafosVet[i].second) / totalDigrafos << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}