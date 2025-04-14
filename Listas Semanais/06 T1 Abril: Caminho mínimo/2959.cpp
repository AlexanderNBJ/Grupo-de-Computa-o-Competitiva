/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <bitset>

int main()
{

    int nBairros, nConexoes, nPerguntas;

    std::cin >> nBairros >> nConexoes >> nPerguntas;

    std::vector<std::bitset<400>> matriz(nBairros);

    for (int i = 0; i < nConexoes; i++)
    {

        int bairroA, bairroB;
        std::cin >> bairroA >> bairroB;

        matriz[bairroA - 1][bairroB - 1] = 1;
        matriz[bairroB - 1][bairroA - 1] = 1;
    }

    for (int j = 0; j < nBairros; j++)
    {
        for (int i = 0; i < nBairros; i++)
        {
            if (matriz[i][j])
            {
                matriz[i] |= matriz[j];
            }
        }
    }

    for (int i = 0; i < nPerguntas; i++)
    {

        int bairroA, bairroB;

        std::cin >> bairroA >> bairroB;

        if (matriz[bairroA - 1][bairroB - 1])
        {
            std::cout << "Lets que lets" << std::endl;
        }
        else
        {
            std::cout << "Deu ruim" << std::endl;
        }
    }

    return 0;
}