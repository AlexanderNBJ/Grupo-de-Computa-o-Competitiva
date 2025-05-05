/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, k;

    while (cin >> r >> k)
    {
        vector<int> graus(r, 0);

        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            graus[a]++;
            graus[b]++;
        }

        vector<bool> dp(k + 1, false);
        dp[0] = true;

        for (int i : graus)
        {
            for (int j = k; j >= i; j--)
            {
                if (dp[j - i])
                {
                    dp[j] = true;
                }
            }
        }

        if (dp[k])
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}