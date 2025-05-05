/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>

using namespace std;

int main() {
    int N, num, atual, cont = 1, max_cont = 1;

    cin >> N;
    cin >> num;
    atual = num;

    for (int i = 1; i < N; i++) { 
        cin >> num;
        if (num == atual) {
            cont++;
        } else {
            max_cont = max(max_cont, cont); 
            cont = 1;
            atual = num;
        }
    }

    max_cont = max(max_cont, cont);

    cout << max_cont << endl;

    return 0;
}