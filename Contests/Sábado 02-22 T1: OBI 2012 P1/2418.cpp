/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
#include <algorithm> 
#include <iomanip>  

using namespace std;

int main() {
    float notas[5];
    for (int i = 0; i < 5; i++) {
        cin >> notas[i];
    }
    sort(notas, notas + 5);
    float notaFinal = notas[1] + notas[2] + notas[3];
    cout << fixed << setprecision(1) << notaFinal << endl;
    return 0;
}