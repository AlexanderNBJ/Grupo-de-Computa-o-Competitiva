/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    while (cin >> N >> K) {
        vector<int> vet(N);
        for (int i = 0; i < N; i++) {
            cin >> vet[i];
        }
        nth_element(vet.begin(), vet.begin() + K, vet.end(), greater<int>());

        long long resultado = 0;
        for (int i = 0; i < K; i++) {
            resultado = (resultado + vet[i]) % MOD;
        }

        cout << resultado << "\n";
    }

    return 0;
}


