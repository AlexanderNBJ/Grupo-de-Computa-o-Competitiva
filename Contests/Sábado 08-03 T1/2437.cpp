/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    DISTÂNCIA DE MANHATTAN
*/

#include <iostream>
#include <cmath>
int main()
{

    int posInicialX;
    int posInicialY;

    std::cin >> posInicialX >> posInicialY;

    int posFinalX;
    int posFinalY;

    std::cin >> posFinalX >> posFinalY;

    int resposta = std::abs(posFinalX - posInicialX) + std::abs(posFinalY - posInicialY);

    std::cout << resposta << std::endl;
}