/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    int X, Y, Z;
    cin >> A >> B >> C;
    cin >> X >> Y >> Z;
    if (C > Z) {
        cout << "0" << endl;
        return 0;
    }
    int n_largura = X / A;
    int n_comp = Y / B;
    int n_alt = Z / C;
    int total = n_largura * n_comp * n_alt;
    cout << total << endl;
    return 0;
}