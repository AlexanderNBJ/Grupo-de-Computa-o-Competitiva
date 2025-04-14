/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main(){
    int receitaDeBolo[3];
    int qtdeBolos = 0;

    for(int i=0; i<3; i++){
        cin >> receitaDeBolo[i];
    }

    while(1){
        if(receitaDeBolo[0]-2 >=0 && receitaDeBolo[1]-3 >=0 && receitaDeBolo[2] -5 >=0){
            receitaDeBolo[0] -= 2;
            receitaDeBolo[1] -= 3;
            receitaDeBolo[2] -= 5;
            qtdeBolos++;
        }
        else{
            cout << qtdeBolos << endl;
            break;
        }
    }

    return 0;
}