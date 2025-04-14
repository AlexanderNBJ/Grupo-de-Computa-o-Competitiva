/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    ELEVADOR
*/

#include <iostream>
using namespace std;

int main(){
    int n, capacidade;
    cin >> n >> capacidade;

    int qtdePessoas = 0;
    char flag = 'N';

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;

        qtdePessoas = qtdePessoas + y -x;
        if(qtdePessoas > capacidade){
            flag = 'S';
        }
    }

    cout << flag << endl;

    return 0;
}