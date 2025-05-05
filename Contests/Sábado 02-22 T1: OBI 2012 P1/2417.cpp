/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main(){
    int Cormengo[3];
    int Flaminthians[3];

    for(int i=0; i<3; i++){
        cin >> Cormengo[i];
    }

    for(int i=0; i<3; i++){
        cin >> Flaminthians[i];
    }

    int saldoCormengo = Cormengo[0]*3 + Cormengo[1];
    int saldoFlaminthians = Flaminthians[0]*3 + Flaminthians[1];

    if(saldoCormengo > saldoFlaminthians){
        cout << "C" << endl;
    }
    else if(saldoCormengo < saldoFlaminthians){
        cout << "F" << endl;
    }
    else{
        if(Cormengo[2] > Flaminthians[2]){
            cout << "C" << endl;
        }
        else if(Cormengo[2] < Flaminthians[2]){
            cout << "F" << endl;
        }
        else{
            cout << "=" << endl;
        }
    }

 return 0;
}