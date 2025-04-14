/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen
*/
#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

using namespace std;

// Estrutura para armazenar os dados de um aluno
struct Aluno {
    string nome;
    int habilidade;
};

// Função para comparar alunos por habilidade (ordem decrescente)
bool compararHabilidade(const Aluno &a, const Aluno &b) {
    return a.habilidade > b.habilidade;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<Aluno> alunos(N);

    for (int i = 0; i < N; i++) {
        cin >> alunos[i].nome >> alunos[i].habilidade;
    }

    sort(alunos.begin(), alunos.end(), compararHabilidade);

    vector<vector<string>> times(T);

    for (int i = 0; i < N; i++) {
        int timeAtual = i % T;
        times[timeAtual].push_back(alunos[i].nome);
    }

    for (int i = 0; i < T; i++) {
        cout << "Time " << i + 1 << endl;

        
        sort(times[i].begin(), times[i].end());

        for (const string &nome : times[i]) {
            cout << nome << endl;
        }

        cout << endl;
    }

    return 0;
}