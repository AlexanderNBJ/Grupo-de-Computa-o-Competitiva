/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

std::string stringEmComum(const std::string &stringA, const std::string &stringB)
{
    std::string emComum;
    for (char letra : stringA)
    {
        if (stringB.find(letra) != std::string::npos)
        {
            emComum += letra;
        }
    }
    return emComum;
}

std::string unirStrings(const std::string &stringA, const std::string &stringB)
{
    std::string uniao = stringA;
    for (char letra : stringB)
    {
        if (uniao.find(letra) == std::string::npos)
        {
            uniao += letra;
        }
    }
    return uniao;
}

int main()
{
    int nos;
    std::string matriz[205][205];

    while (std::cin >> nos && nos != 0)
    {

        for (int i = 0; i < nos; i++)
        {
            for (int j = 0; j < nos; j++)
            {
                matriz[i][j].clear();
            }
        }

        int a, b;
        std::string empresas;
        while (std::cin >> a >> b && (a + b != 0))
        {
            std::cin >> empresas;
            matriz[a - 1][b - 1] = unirStrings(matriz[a - 1][b - 1], empresas); // Acumula
        }

        for (int k = 0; k < nos; k++)
        {
            for (int i = 0; i < nos; i++)
            {
                for (int j = 0; j < nos; j++)
                {
                    std::string emComum = stringEmComum(matriz[i][k], matriz[k][j]);

                    matriz[i][j] = unirStrings(matriz[i][j], emComum);
                }
            }
        }

        while (std::cin >> a >> b && (a + b != 0))
        {
            if (matriz[a - 1][b - 1].empty())
            {
                std::cout << "-" << std::endl;
            }
            else
            {
                std::sort(matriz[a - 1][b - 1].begin(), matriz[a - 1][b - 1].end());
                std::cout << matriz[a - 1][b - 1] << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}