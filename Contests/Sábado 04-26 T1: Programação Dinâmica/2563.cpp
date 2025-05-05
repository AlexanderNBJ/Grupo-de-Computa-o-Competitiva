/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>

int main()
{

    int N, K;

    while (std::cin >> N >> K)
    {

        std::vector<std::pair<int, int>> analogimons(N);

        for (int i = 0; i < N; i++)
        {

            std::cin >> analogimons[i].first;
        }

        for (int i = 0; i < N; i++)
        {

            std::cin >> analogimons[i].second;
        }

        std::vector<int> mochila(K + 1, 0);

        for (int i = 0; i < N; i++)
        {

            for (int j = K; j >= analogimons[i].second; j--)
            {

                mochila[j] = std::max(mochila[j], mochila[j - analogimons[i].second] + analogimons[i].first);
            }
        }

        std::cout << mochila[K] << std::endl;
    }
}