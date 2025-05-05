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

        int bambuA, bambuB;
        std::cin >> bambuA >> bambuB;

        std::cout << (bambuA * bambuB) / 2 << " cm2" << std::endl;
    }

    return 0;
}