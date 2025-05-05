/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    SEDEX
*/

#include <iostream>
using namespace std;

int main(){
    int diametro;
    cin >> diametro;

    int x,y,z;
    cin >> x >> y >> z;

    if(diametro<=x && diametro<=y && diametro<=z){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }

    return 0;
}