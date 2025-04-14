/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string vogais;
    string frase;

    while (getline(cin, vogais)) {
        if (vogais.empty()) {
            continue;
        }
        getline(cin, frase);

        unordered_set<char> vogaisSemRep(vogais.begin(), vogais.end());
        int contador = 0;

        for (char c : frase) {
            if (vogaisSemRep.find(c) != vogaisSemRep.end()) {
                contador++;
            }
        }

        cout << contador << endl;
    }

    return 0;
}