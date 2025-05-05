/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    while (n!=0 || k!=0) {
        int perguntas[101] = {};
        int qtde = 0;

        for (int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            perguntas[tmp]++;
        }

        for (int i=1; i<=100; i++) {
            if (perguntas[i] >= k) {
                qtde++;
            }
        }

        cout << qtde << endl;
        cin >> n >> k;
    }

    return 0;
}