/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;

    while (cin >> n, n != "00e0")
    {
        unsigned long long num = (n[0] - '0') * 10 + (n[1] - '0');
        int zeros = n[3] - '0';

        for (int i = 0; i < zeros; i++)
        {
            num *= 10;
        }

        unsigned long long maiorPotDe2 = 1;
        while (maiorPotDe2 * 2 <= num)
        {
            maiorPotDe2 *= 2;
        }

        unsigned long long sobrevivente = 2 * (num - maiorPotDe2) + 1;
        cout << sobrevivente << endl;
    }
}