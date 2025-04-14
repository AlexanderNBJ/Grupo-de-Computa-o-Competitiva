/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    VOLUME DA TV
*/

#include <iostream>

using namespace std;

int main(){
    int init, trocas;
    cin >> init >> trocas;

    while(trocas){
        int alteracao;
        cin >> alteracao;

        if(alteracao+init >=100){
            init = 100;
        }
        else if(alteracao+init <= 0){
            init = 0;
        }
        else{
            init +=alteracao;
        }

        trocas--;
    }

    cout << init << endl;
    return 0;
}