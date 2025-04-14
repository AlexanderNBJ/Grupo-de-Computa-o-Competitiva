/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double calculaArea(const vector<double> &tiras, double corte)
{

    double area = 0;

    for (int i = tiras.size() - 1; i >= 0; i--)
    {
        if (tiras[i] <= corte)
        {
            return area;
        }

        area += (tiras[i] - corte);
    }

    return area;
}

double buscaBinaria(const vector<double> &tiras, double areaDesejada)
{
    double inicio = 0;
    double final = tiras[tiras.size() - 1];
    double precisao = 1e-9;
    double corte;

    while ((final - inicio) > precisao)
    {

        corte = (inicio + final) / 2.0;

        double diferenca = calculaArea(tiras, corte) - areaDesejada;

        if (diferenca > 0)
        {
            inicio = corte;
        }
        else
        {
            final = corte;
        }
    }

    return inicio;
}

int main()
{
    int quantidade;
    int areaDesejada;
    while (cin >> quantidade >> areaDesejada && quantidade != 0)
    {

        vector<double> tiras(quantidade);
        double areaTotal = 0.0;

        for (double i = 0; i < quantidade; i++)
        {
            cin >> tiras[i];
            areaTotal += tiras[i];
        }

        if (areaTotal == areaDesejada)
        {
            std::cout << ":D" << std::endl;
        }
        else if (areaTotal < areaDesejada)
        {
            std::cout << "-.-" << std::endl;
        }
        else
        {

            std::sort(tiras.begin(), tiras.end());

            double corte = buscaBinaria(tiras, areaDesejada);

            std::cout << fixed << setprecision(4) << corte << std::endl;
        }
    }

    return 0;
}


