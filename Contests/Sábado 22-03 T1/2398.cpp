/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> pistas(K, vector<int>(3));
    for (int i = 0; i < K; i++) {
        cin >> pistas[i][0] >> pistas[i][1] >> pistas[i][2];
    }

    set<pair<int, int>> candidatos;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            bool valido = true;
            for (const auto& pista : pistas) {
                int distancia = abs(x - pista[0]) + abs(y - pista[1]);
                if (distancia != pista[2]) {
                    valido = false;
                    break;
                }
            }
            if (valido) {
                candidatos.insert({x, y});
            }
        }
    }

    if (candidatos.size() == 1) {
        auto tesouro = *candidatos.begin();
        cout << tesouro.first << " " << tesouro.second << endl;
    } else {
        cout << "-1 -1" << endl;
    }

    return 0;
}