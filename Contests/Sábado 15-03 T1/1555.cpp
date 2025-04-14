/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <cmath>

int main()
{

    int quantidadeCasos;
    std::cin >> quantidadeCasos;

    for (int i = 0; i < quantidadeCasos; i++)
    {

        int x, y;
        std::cin >> x >> y;
        int rafael = std::pow((3 * x), 2) + std::pow(y, 2);
        int beto = 2 * std::pow(x, 2) + std::pow(5 * y, 2);
        int carlos = -100 * x + std::pow(y, 3);

        if (rafael > beto && rafael > carlos)
        {
            std::cout << "Rafael ganhou" << std::endl;
        }
        else if (beto > rafael && beto > carlos)
        {
            std::cout << "Beto ganhou" << std::endl;
        }
        else
        {
            std::cout << "Carlos ganhou" << std::endl;
        }
    }

    return 0;
}