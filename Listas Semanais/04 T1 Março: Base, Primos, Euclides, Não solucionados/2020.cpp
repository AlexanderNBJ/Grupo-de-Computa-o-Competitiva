/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string decodificar(const vector<int>& ops) {
    list<int> ordemLinhas;
    for (int i = 0; i < 26; ++i) {
        ordemLinhas.push_back(i);
    }

    vector<list<int>> ordemColunas(26);
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            ordemColunas[i].push_back(j);
        }
    }

    string resultado;

    for (int op : ops) {
        if (op == 27) {
            resultado += ' ';
            continue;
        }

        int indice = op - 1;
        if (indice < 0 || indice >= 26) continue;

        auto itLinha = ordemLinhas.begin();
        advance(itLinha, indice);
        int linhaAtual = *itLinha;

        list<int>& cols = ordemColunas[linhaAtual];
        auto itColuna = cols.begin();
        advance(itColuna, indice);
        int colunaAtual = *itColuna;

        resultado += 'A' + colunaAtual;

        for (int r = 0; r < 26; ++r) {
            list<int>& colunas = ordemColunas[r];
            auto it = colunas.begin();
            advance(it, indice);
            int valor = *it;
            colunas.erase(it);
            colunas.push_back(valor);
        }

        itLinha = ordemLinhas.begin();
        advance(itLinha, indice);
        int linhaMovida = *itLinha;
        ordemLinhas.erase(itLinha);
        ordemLinhas.push_back(linhaMovida);
    }

    return resultado;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numeroLista = 1;
    bool primeiroCaso = true;

    int n;
    while (cin >> n) {
        cin.ignore();

        vector<string> presentes;
        for (int i = 0; i < n; ++i) {
            string linha;
            getline(cin, linha);
            stringstream ss(linha);
            vector<int> ops;
            int num;
            while (ss >> num) ops.push_back(num);
            string nome = decodificar(ops);
            presentes.push_back(nome);
        }

        sort(presentes.begin(), presentes.end());

        if (!primeiroCaso) cout << '\n';
        primeiroCaso = false;

        cout << "LISTA #" << numeroLista << ":\n";
        for (const string& presente : presentes) {
            cout << presente << '\n';
        }

        numeroLista++;
    }

    return 0;
}