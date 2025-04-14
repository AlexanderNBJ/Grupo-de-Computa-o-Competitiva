/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main(){
    int L;
    cin >> L;
    int cont = 1;

    while (L >= 2){
        L/=2;
        cont*=4;
    }

    cout << cont << endl;

    return 0;
}