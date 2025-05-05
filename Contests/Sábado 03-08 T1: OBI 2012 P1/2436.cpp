/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    ROBÔ
*/

#include <iostream>
#include <vector>
int main()
{

    int linhas;
    int colunas;

    std::cin >> linhas >> colunas;

    int linhaInicial;
    int colunaInicial;

    std::cin >> linhaInicial >> colunaInicial;

    std::vector<std::vector<int>> salao(linhas, std::vector<int>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            std::cin >> salao[i][j];
        }
    }

    int posicaoAtualX = linhaInicial - 1;
    int posicaoAtualY = colunaInicial - 1;

    while (1)
    {

        salao[posicaoAtualX][posicaoAtualY] = 0;

        if (posicaoAtualX + 1 < linhas && salao[posicaoAtualX + 1][posicaoAtualY] == 1)
        {
            posicaoAtualX++;
        }
        else if (posicaoAtualX - 1 >= 0 && salao[posicaoAtualX - 1][posicaoAtualY] == 1)
        {
            posicaoAtualX--;
        }
        else if (posicaoAtualY + 1 < colunas && salao[posicaoAtualX][posicaoAtualY + 1] == 1)
        {
            posicaoAtualY++;
        }
        else if (posicaoAtualY - 1 >= 0 && salao[posicaoAtualX][posicaoAtualY - 1] == 1)
        {
            posicaoAtualY--;
        }
        else
        {
            break;
        }

        salao[posicaoAtualX][posicaoAtualY] = 0;
    }

    std::cout << posicaoAtualX + 1 << " " << posicaoAtualY + 1 << std::endl;

    return 0;
}