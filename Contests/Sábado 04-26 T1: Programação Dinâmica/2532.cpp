/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main()
{

    int N, P;

    while (std::cin >> N >> P)
    {
        int INF = std::numeric_limits<int>::max();

        std::vector<std::pair<int, int>> feiticos(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> feiticos[i].first >> feiticos[i].second;
        }

        std::vector<int> mochila(P + 1001, INF);

        mochila[0] = 0;

        for (auto [dano, mana] : feiticos)
        {
            for (int i = P + 1000; i >= dano; i--)
            {
                if (mochila[i - dano] != INF)
                {
                    mochila[i] = std::min(mochila[i], mochila[i - dano] + mana);
                }
            }
        }

        int resposta = INF;

        for (int i = P; i <= P + 1000; i++)
        {
            resposta = std::min(resposta, mochila[i]);
        }

        if (resposta == INF)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << resposta << std::endl;
        }
    }
}