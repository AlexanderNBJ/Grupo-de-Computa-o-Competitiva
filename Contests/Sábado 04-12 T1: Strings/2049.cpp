/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int cont = 1;
    bool firstInstance = true; // Para controlar a linha em branco antes da primeira instância

    while (true) {
        cin >> n;
        if (n == "0") {
            break;
        }

        if (!firstInstance) {
            cout << endl; // Linha em branco entre instâncias
        }
        firstInstance = false;

        string s;
        cin >> s;
        bool condicao = false;

        for (size_t i = 0; i <= s.size() - n.size(); i++) {
            if (s.substr(i, n.size()) == n) {
                condicao = true;
                break;
            }
        }

        cout << "Instancia " << cont << endl;
        cout << (condicao ? "verdadeira" : "falsa") << endl;
        cont++;
    }

    return 0;
}