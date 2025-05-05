/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio RIttershaussen Novaes
*/

#include <iostream>
using namespace std;

int main(){
    int x, cont;
    cin >> x;
    cont =7;
    
    for(int i=11; i<=x; i++){
        if(i>=11 && i<=30){
            cont++;
        }
        else if(i>=31 && i<=100){
            cont+=2;
        }
        else{
            cont+=5;
        }
    }
    cout << cont << endl;
    
}