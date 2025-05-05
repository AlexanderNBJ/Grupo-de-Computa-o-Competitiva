/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    if (N <= 2) {
        cout << 1 << endl;
        return 0;
    }

    int partes = 1;
    int razao = seq[1] - seq[0];
    for (int i = 2; i < N; i++) {
        int nova_razao = seq[i] - seq[i - 1];
        if (nova_razao != razao) {
            partes++;
            if (i + 1 < N) {
                razao = seq[i + 1] - seq[i];
                i++;
            }
        }
    }

    cout << partes << endl;

    return 0;
}