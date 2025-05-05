/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>

int main()
{

    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {

        std::string palavraAtual;
        std::cin >> palavraAtual;

        if (i != 0)
        {
            std::cout << " ";
        }
        if (palavraAtual.size() == 3 && palavraAtual.substr(0, 2) == "OB")
        {
            std::cout << "OBI";
        }
        else if (palavraAtual.size() == 3 && palavraAtual.substr(0, 2) == "UR")
        {
            std::cout << "URI";
        }
        else
        {
            std::cout << palavraAtual;
        }
    }

    std::cout << std::endl;

    return 0;
}