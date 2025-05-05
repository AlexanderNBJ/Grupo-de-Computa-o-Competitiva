/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N;

        set<string> inventario;

        for (int i = 0; i < N; ++i) {
            string item, comando;
            cin >> item >> comando;

            if (comando == "chirrin") {
                inventario.insert(item);
            } else if (comando == "chirrion") {
                inventario.erase(item);
            }
        }
        cout << "TOTAL" << endl;
        for (const auto& x : inventario) {
            cout << x << endl;
        }
    }

    return 0;
}