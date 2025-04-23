/*
    Alunos: Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>  // scanf, printf

using namespace std;

struct Aresta {
    int a, b, custo;
    bool operator<(const Aresta& other) const {
        return custo < other.custo;
    }
};

const int MAXN = 100001;
vector<int> chefe(MAXN), ranque(MAXN, 0);

int find(int x) {
    if (chefe[x] != x)
        chefe[x] = find(chefe[x]);
    return chefe[x];
}

bool unir(int x, int y) {
    int raizX = find(x);
    int raizY = find(y);
    if (raizX == raizY)
        return false;
    if (ranque[raizX] < ranque[raizY])
        chefe[raizX] = raizY;
    else {
        chefe[raizY] = raizX;
        if (ranque[raizX] == ranque[raizY])
            ranque[raizX]++;
    }
    return true;
}

int kruskal(int n, vector<Aresta>& arestas) {
    sort(arestas.begin(), arestas.end());

    for (int i = 1; i <= n; ++i) {
        chefe[i] = i;
        ranque[i] = 0;
    }

    int total = 0, usados = 0;
    for (const auto& e : arestas) {
        if (unir(e.a, e.b)) {
            total += e.custo;
            usados++;
            if (usados == n - 1)
                break;
        }
    }

    return (usados == n - 1) ? total : -1;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        vector<Aresta> arestas(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &arestas[i].a, &arestas[i].b, &arestas[i].custo);
        }

        int resultado = kruskal(n, arestas);
        if (resultado == -1)
            printf("impossivel\n");
        else
            printf("%d\n", resultado);
    }
    return 0;
}
