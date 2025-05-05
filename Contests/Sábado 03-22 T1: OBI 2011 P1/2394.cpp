/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int vet[N];
    for (int i = 0; i < N; i++) {
        vet[i] = 0;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            vet[i] += x;
        }
    }

    int menor = vet[0];
    int pos = 0;
    for (int x = 1; x < N; x++) {
        if (vet[x] < menor) {
            menor = vet[x];
            pos = x;
        }
    }

    cout << pos + 1 << endl;

    return 0;
}