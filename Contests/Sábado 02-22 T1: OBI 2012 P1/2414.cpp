/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main(){
    int valor;
    int maiorValor = -1;
    
    while(1){
        cin >> valor;

        if(valor == 0){
            break;
        }
        else{
            if(valor > maiorValor){
                maiorValor = valor;
            }
        }
    }

    cout << maiorValor << endl;
}