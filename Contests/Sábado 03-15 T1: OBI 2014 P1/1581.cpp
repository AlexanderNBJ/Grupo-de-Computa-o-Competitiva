/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>

int main()
{

    int quantidadeCasos;

    std::cin >> quantidadeCasos;

    for (int i = 0; i < quantidadeCasos; i++)
    {

        int quantidadePessoas;
        std::cin >> quantidadePessoas;

        std::string primeiraLingua;
        std::cin >> primeiraLingua;
        bool ingles = false;

        for (int i = 1; i < quantidadePessoas; i++)
        {
            std::string linguaAtual;
            std::cin >> linguaAtual;

            if (linguaAtual != primeiraLingua)
            {
                ingles = true;
            }
        }

        if (!ingles)
        {
            std::cout << primeiraLingua << std::endl;
        }
        else
        {
            std::cout << "ingles" << std::endl;
        }
    }
}