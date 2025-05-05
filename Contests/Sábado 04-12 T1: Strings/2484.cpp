/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string palavra;

    while(cin >> palavra){
        int size = palavra.size();

        while(size != 0){
            for(int i=0; i< palavra.size()-size; i++){
                cout << " ";
            }

            for(int i=0; i<size; i++){
                if(i == size-1){
                    cout << palavra[i];
                }
                else
                    cout << palavra[i] << " ";
            }
            cout << endl;
            size--;
        }
        cout << endl;
    }
}