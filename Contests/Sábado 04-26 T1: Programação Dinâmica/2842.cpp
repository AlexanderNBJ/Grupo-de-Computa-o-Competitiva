// Alunos: Alexander Neves, Arthur de Almeida, Davi Paulino

#include <iostream>
#include <vector>

using namespace std;

int pd_encontra_maior_subsequencia_comum(const string &a, const string &b, int size_a, int size_b, vector<vector<int>> &memo)
{
    if (size_a == 0 || size_b == 0)
    {
        return 0;
    }

    if (memo[size_a][size_b] != -1)
    {
        return memo[size_a][size_b];
    }

    if (a[size_a - 1] == b[size_b - 1])
    {
        memo[size_a][size_b] = 1 + pd_encontra_maior_subsequencia_comum(a, b, size_a - 1, size_b - 1, memo);
        return memo[size_a][size_b];
    }

    memo[size_a][size_b] = max(pd_encontra_maior_subsequencia_comum(a, b, size_a - 1, size_b, memo),
                               pd_encontra_maior_subsequencia_comum(a, b, size_a, size_b - 1, memo));
    return memo[size_a][size_b];
}

int main()
{
    string a, b;
    cin >> a;
    cin >> b;

    int size_a = a.length();
    int size_b = b.length();
    vector<vector<int>> memo(size_a + 1, vector<int>(size_b + 1, -1));

    int subsequecia_comum = pd_encontra_maior_subsequencia_comum(a, b, size_a, size_b, memo);
    int caracteres_diferentes = size_a + size_b - 2 * subsequecia_comum;

    cout << subsequecia_comum + caracteres_diferentes << '\n';
}