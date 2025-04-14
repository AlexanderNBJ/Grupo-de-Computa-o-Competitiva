/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int dia;
    cin >> dia;

    while(dia){
        vector<pair<int, int>> morteBacts;
        int diaUm, diaDois, diaTres, diaQuatro;
        int aux = 0;

        cin >> diaUm >> diaDois >> diaTres >> diaQuatro;

        morteBacts.push_back({5,diaUm});
        morteBacts.push_back({6,diaDois});
        morteBacts.push_back({7,diaTres});
        morteBacts.push_back({8,diaQuatro});

        int qtdeBacts = (diaUm+diaDois+diaTres+diaQuatro)*2

        for(int i=5; i<dia; i++){

        }
    }
}