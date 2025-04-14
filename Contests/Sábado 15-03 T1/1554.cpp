/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <cmath>
#include <climits>
int main()
{

    int quantidadeCasos;
    int quantidadeBolas;

    std::cin >> quantidadeCasos;

    for (int i = 0; i < quantidadeCasos; i++)
    {
        std::cin >> quantidadeBolas;
        int xBranca, yBranca;

        std::cin >> xBranca >> yBranca;

        double menorDistancia = std::numeric_limits<double>::max();
        int menorBola = -1;

        for (int i = 1; i <= quantidadeBolas; i++)
        {

            int xBola, yBola;

            std::cin >> xBola >> yBola;

            double distanciaAtual = std::sqrt(((xBranca - xBola) * (xBranca - xBola)) + ((yBranca - yBola) * (yBranca - yBola)));

            if (distanciaAtual < menorDistancia)
            {
                menorDistancia = distanciaAtual;
                menorBola = i;
            }
        }
        std::cout << menorBola << std::endl;
    }

    return 0;
}