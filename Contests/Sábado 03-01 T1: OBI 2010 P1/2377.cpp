/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    PEDÁGIO
*/

#include <iostream>
using namespace std;

int main(){
    int comprimento, distPedagio;
    int custoKm, custoPedagio;

    cin >> comprimento >> distPedagio;
    cin >> custoKm >> custoPedagio;

    int custoTotal = 0;

    for(int i=1; i<=comprimento; i++){
        custoTotal+=custoKm;

        if(i%distPedagio == 0){
            custoTotal+= custoPedagio;
        }
    }

    cout << custoTotal << endl;

    return 0;
}