/*
    Alunos: Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M, S;
        cin >> N >> M >> S;
        if (N == 0 && M == 0 && S == 0)
            break;

        vector<int> inimigos(N), refens(N), grauEntrada(N, 0);
        vector<vector<int>> grafo(N);

        for (int i = 0; i < N; ++i) cin >> inimigos[i];
        for (int i = 0; i < N; ++i) cin >> refens[i];

        for (int i = 0; i < M; ++i) {
            int A, B;
            cin >> A >> B;
            --A; --B;
            grafo[A].push_back(B);
            grauEntrada[B]++;
        }

        vector<bool> visitado(N, false);
        queue<int> prontos;
        bool mudou = true;

        while (mudou) {
            mudou = false;

            for (int i = 0; i < N; ++i) {
                if (!visitado[i] && grauEntrada[i] == 0 && S > inimigos[i]) {
                    prontos.push(i);
                    visitado[i] = true;
                    mudou = true;
                }
            }

            while (!prontos.empty()) {
                int atual = prontos.front();
                prontos.pop();

                S += refens[atual];

                for (int vizinho : grafo[atual]) {
                    grauEntrada[vizinho]--;
                }
            }
        }

        bool todosVisitados = true;
        for (int i = 0; i < N; ++i) {
            if (!visitado[i]) {
                todosVisitados = false;
                break;
            }
        }

        cout << (todosVisitados ? "possivel" : "impossivel") << '\n';
    }

    return 0;
}
