/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    GARÇOM
*/

#include <iostream>
using namespace std;

int main(){
    int casos;
    int coposQuebrados = 0;
    cin >> casos;

    for(int i=0; i<casos; i++){
        int x,y;
        cin >> x >> y;

        if(x > y){
            coposQuebrados+=y;
        }
    }

    cout << coposQuebrados << endl;

    return 0;
}