/*
Alexander Neves
Davi Laboissiere
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

const int LOG = 20;

std::vector<std::vector<int>> listaAdjacencia;
std::vector<std::vector<int>> ancestrais;
std::vector<int> profundidade;

void bfs(int raiz, int quantidade)
{
    std::queue<int> q;
    q.push(raiz);
    profundidade[raiz] = 0;
    ancestrais[0][raiz] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : listaAdjacencia[u])
        {
            if (profundidade[v] == -1)
            {
                profundidade[v] = profundidade[u] + 1;
                ancestrais[0][v] = u;
                q.push(v);
            }
        }
    }
}

void preprocessamento(int quantidade)
{
    for (int k = 1; k < LOG; k++)
    {
        for (int u = 1; u <= quantidade; u++)
        {
            if (ancestrais[k - 1][u] != -1)
            {
                ancestrais[k][u] = ancestrais[k - 1][ancestrais[k - 1][u]];
            }
        }
    }
}

int lca(int u, int v)
{
    if (profundidade[u] < profundidade[v])
    {
        std::swap(u, v);
    }

    for (int k = LOG - 1; k >= 0; k--)
    {
        if (profundidade[u] - (1 << k) >= profundidade[v])
        {
            u = ancestrais[k][u];
        }
    }

    if (u == v)
    {
        return u;
    }

    for (int k = LOG - 1; k >= 0; k--)
    {
        if (ancestrais[k][u] != -1 && ancestrais[k][u] != ancestrais[k][v])
        {
            u = ancestrais[k][u];
            v = ancestrais[k][v];
        }
    }

    return ancestrais[0][u];
}

int distancia(int u, int v)
{
    int ancestral = lca(u, v);
    return profundidade[u] + profundidade[v] - 2 * profundidade[ancestral];
}

int main()
{
    int quantidade;
    std::cin >> quantidade;

    listaAdjacencia.resize(quantidade + 1);
    ancestrais.resize(LOG, std::vector<int>(quantidade + 1, -1));
    profundidade.resize(quantidade + 1, -1);

    std::vector<int> numeros(quantidade + 1);
    std::map<int, std::vector<int>> valorPorPosicao;

    for (int i = 1; i <= quantidade; i++)
    {
        std::cin >> numeros[i];
        valorPorPosicao[numeros[i]].push_back(i);
    }

    for (int i = 0; i < quantidade - 1; i++)
    {
        int numeroA, numeroB;
        std::cin >> numeroA >> numeroB;
        listaAdjacencia[numeroA].push_back(numeroB);
        listaAdjacencia[numeroB].push_back(numeroA);
    }

    bfs(1, quantidade);
    preprocessamento(quantidade);

    int total = 0;
    for (const auto &par : valorPorPosicao)
    {
        const std::vector<int> &posicoes = par.second;
        if (posicoes.size() >= 2)
        {
            int u = posicoes[0];
            int v = posicoes[1];
            total += distancia(u, v);
        }
    }

    std::cout << total << std::endl;

    return 0;
}
