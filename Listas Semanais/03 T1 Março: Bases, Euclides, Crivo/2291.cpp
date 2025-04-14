/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#define max 1000000

using namespace std;

int main() {
    static int soma_divisores[max + 1] = {0}; 
    static long long numeros_divinos[max + 1] = {0}; 
    for (int i = 1; i <= max; i++) { 
        for (int j = i; j <= max; j += i) { 
            soma_divisores[j] += i;
        }
    }

    long long acumulado = 0; 
    for (int i = 1; i <= max; i++) {
        acumulado += soma_divisores[i];
        numeros_divinos[i] = acumulado;
    }

    int n;
    while (cin >> n && n != 0) {
        cout << numeros_divinos[n] << endl;
    }

    return 0;
}
