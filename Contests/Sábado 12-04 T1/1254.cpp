/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string minusculo(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return s;
}

int main()
{

    std::string tagOriginal;
    std::string tagNova;

    std::string frase;

    while (std::cin >> tagOriginal >> tagNova)
    {
        tagOriginal = minusculo(tagOriginal);

        std::cin.ignore();
        std::getline(std::cin, frase);
        for (int i = 0; i <= frase.size() - tagOriginal.size(); i++)
        {
            if (frase[i] == '<')
            {
                for (int j = i + 1; frase[j] != '>' && j <= frase.size() - tagOriginal.size(); j++)
                {

                    if (minusculo(frase.substr(j, tagOriginal.size())) == tagOriginal)
                    {
                        frase.replace(j, tagOriginal.size(), tagNova);
                    }
                }
            }
        }

        std::cout << frase << std::endl;
    }
}