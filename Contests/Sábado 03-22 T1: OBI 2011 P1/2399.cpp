/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int vet[N];

    for (int i = 0; i < N; i++) {
        cin >> vet[i];
    }

    for (int i = 0; i < N; i++) {
        int cont = 0;
        if (i - 1 >= 0 && vet[i - 1] == 1) cont++;
        if (vet[i] == 1) cont++;
        if (i + 1 < N && vet[i + 1] == 1) cont++;
        cout << cont << endl;
    }

    return 0;
}