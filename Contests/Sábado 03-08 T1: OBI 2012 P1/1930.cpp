/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    TOMADAS
*/

#include <iostream>

int main()
{

    int tomadas = -3;

    for (int i = 0; i < 4; i++)
    {
        int valor;
        std::cin >> valor;
        tomadas += valor;
    }

    std::cout << tomadas << std::endl;

    return 0;
}