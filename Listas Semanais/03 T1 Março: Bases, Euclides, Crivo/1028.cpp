/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen Novaes
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int F1, F2;
        cin >> F1 >> F2;
        while(F2 != 0) {
            int temp = F2;
            F2 = F1 % F2;
            F1 = temp;
        }
        cout << F1 << "\n";
    }
    return 0;
}
