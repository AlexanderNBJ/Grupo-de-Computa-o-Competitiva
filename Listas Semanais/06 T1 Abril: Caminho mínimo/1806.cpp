/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

const int INF = 0x3F3F3F3F;

std::vector<std::pair<int, int>> rotasBino[10001];
std::vector<std::pair<int, int>> rotasCriminosos[10001];
int criminosos[10001] = {0};

int calculaQuantidade(int pontoInicial, int pontoFinal, int nLugares)
{
    std::vector<int> distanciaBino(nLugares + 1, INF);
    std::vector<int> distanciaCriminosos(nLugares + 1, INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
        minHeap;

    bool contagem[10001] = {false};

    minHeap.push({0, pontoInicial});

    distanciaBino[pontoInicial] = 0;

    while (!minHeap.empty())
    {
        int noAtual = minHeap.top().second;

        int distanciaAtual = minHeap.top().first;

        minHeap.pop();

        if (noAtual == pontoFinal)
        {
            break;
        }

        if (distanciaAtual > distanciaBino[noAtual])
        {
            continue;
        }

        for (const auto &rota : rotasBino[noAtual])
        {
            int proximoNo = rota.first;

            int distanciaTotal = rota.second;

            if (distanciaBino[proximoNo] > distanciaAtual + distanciaTotal)
            {
                distanciaBino[proximoNo] = distanciaAtual + distanciaTotal;

                minHeap.push({distanciaBino[proximoNo], proximoNo});
            }
        }
    }

    if (distanciaBino[pontoFinal] == INF)
    {
        return 0;
    }

    int quantidadeCriminosos = 0;

    minHeap = decltype(minHeap)();

    minHeap.push({0, pontoFinal});

    distanciaCriminosos[pontoFinal] = 0;

    while (!minHeap.empty())
    {
        int noAtual = minHeap.top().second;

        int distanciaAtual = minHeap.top().first;

        minHeap.pop();

        if (distanciaAtual > distanciaBino[pontoFinal] || distanciaAtual > distanciaCriminosos[noAtual])
        {
            continue;
        }

        if (!contagem[noAtual])
        {
            quantidadeCriminosos += criminosos[noAtual];

            contagem[noAtual] = true;
        }

        auto processaRotas = [&](const auto &rotas)
        {
            for (const auto &rota : rotas[noAtual])
            {
                int proximoNo = rota.first;
                int distanciaTotal = rota.second;

                if (distanciaCriminosos[proximoNo] > distanciaAtual + distanciaTotal)
                {
                    distanciaCriminosos[proximoNo] = distanciaAtual + distanciaTotal;

                    minHeap.push({distanciaCriminosos[proximoNo], proximoNo});
                }
            }
        };

        processaRotas(rotasBino);
        processaRotas(rotasCriminosos);
    }

    return quantidadeCriminosos;
}

int main()
{

    int nLugares, nRotasBino, nRotasCriminosos, nCriminosos;

    std::cin >> nLugares >> nRotasBino >> nRotasCriminosos >> nCriminosos;

    for (int i = 0; i <= 10000; i++)
    {
        rotasBino[i].clear();

        rotasCriminosos[i].clear();
    }

    memset(criminosos, 0, sizeof(criminosos));

    for (int i = 0; i < nRotasBino; i++)
    {
        int origem, destino, distancia;

        std::cin >> origem >> destino >> distancia;

        rotasBino[origem].emplace_back(destino, distancia);
        rotasBino[destino].emplace_back(origem, distancia);
    }

    for (int i = 0; i < nRotasCriminosos; i++)
    {
        int origem, destino, distancia;

        std::cin >> origem >> destino >> distancia;

        rotasCriminosos[origem].emplace_back(destino, distancia);
        rotasCriminosos[destino].emplace_back(origem, distancia);
    }

    for (int i = 0; i < nCriminosos; i++)
    {
        int local;

        std::cin >> local;

        criminosos[local]++;
    }

    int pontoInicial, pontoFinal;

    std::cin >> pontoInicial >> pontoFinal;

    std::cout << calculaQuantidade(pontoInicial, pontoFinal, nLugares) << std::endl;

    return 0;
}