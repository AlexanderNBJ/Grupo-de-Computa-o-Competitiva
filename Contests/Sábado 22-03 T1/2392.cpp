/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> pedras(N + 1, false);

    for (int i = 0; i < M; i++) {
        int P, D;
        cin >> P >> D;

        for (int pos = P; pos <= N; pos += D) {
            pedras[pos] = true;
        }

        for (int pos = P; pos >= 1; pos -= D) {
            pedras[pos] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << pedras[i] << endl;
    }

    return 0;
}