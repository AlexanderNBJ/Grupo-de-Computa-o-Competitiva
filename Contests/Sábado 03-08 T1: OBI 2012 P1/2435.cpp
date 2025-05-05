/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    CORRIDA
*/

#include <iostream>

struct Charrete
{

    int numero;
    int distancia;
    int velocidade;
};

int main()
{

    Charrete charrete1;
    std::cin >> charrete1.numero >> charrete1.distancia >> charrete1.velocidade;

    float tempoCharrete1 = (float)charrete1.distancia / charrete1.velocidade;

    Charrete charrete2;
    std::cin >> charrete2.numero >> charrete2.distancia >> charrete2.velocidade;

    float tempoCharrete2 = (float)charrete2.distancia / charrete2.velocidade;

    if (tempoCharrete1 < tempoCharrete2)
    {
        std::cout << charrete1.numero << std::endl;
    }
    else
    {
        std::cout << charrete2.numero << std::endl;
    }

    return 0;
}