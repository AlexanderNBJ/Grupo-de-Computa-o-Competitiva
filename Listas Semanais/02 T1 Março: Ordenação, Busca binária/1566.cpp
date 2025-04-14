/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>

int main()
{

    int casosTeste = 0;
    std::cin >> casosTeste;

    for (int i = 0; i < casosTeste; i++)
    {
        int quantidade = 0;
        std::cin >> quantidade;

        int alturas[231] = {0};

        for (int j = 0; j < quantidade; j++)
        {
            int valor;
            std::cin >> valor;
            alturas[valor]++;
        }

        bool primeiro = true;
        for (int j = 20; j < 231; j++)
        {
            for (int k = 0; k < alturas[j]; k++)
            {
                if (!primeiro)
                {
                    std::cout << " ";
                }
                std::cout << j;
                primeiro = false;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}


