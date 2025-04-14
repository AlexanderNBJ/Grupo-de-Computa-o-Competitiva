/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (char &c : s) {
        c = tolower(static_cast<unsigned char>(c));
    }
    bool bolado = false;
    for (int i = 0; i <= s.length() - 5; i++) {
        if (s.substr(i, 5) == "zelda") {
            bolado = true;
            break;
        }
    }

    if (bolado) {
        cout << "Link Bolado" << endl;
    } else {
        cout << "Link Tranquilo" << endl;
    }

    return 0;
}