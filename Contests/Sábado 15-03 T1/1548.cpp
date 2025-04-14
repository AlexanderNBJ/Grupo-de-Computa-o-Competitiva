/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ordena(int& a, int&b){
    return a>b;
}

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int qtdeAlunos;
        cin >> qtdeAlunos;

        vector<int> alunos;
        vector<int> alunosOrdenados;

        for(int i=0; i<qtdeAlunos; i++){
            int tmp;
            cin >> tmp;

            alunos.push_back(tmp);
            alunosOrdenados.push_back(tmp);
        }
        sort(alunosOrdenados.begin(), alunosOrdenados.end(), ordena);

        int qtdeIgual = 0;

        for(int i=0; i<qtdeAlunos; i++){
            if(alunos[i] == alunosOrdenados[i]){
                qtdeIgual++;
            }
        }
        cout << qtdeIgual << endl;

    }

    return 0;
}