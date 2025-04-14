/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
using namespace std;

bool temSubsequencia(string& palavra, string& subst){
    int palavraSize = palavra.size();
    int substSize = subst.size();
    int i = 0;
    int j = 0;
    while(i<palavraSize && j<substSize){
        if(palavra[i]==subst[j]){
            j++;
        }
        i++;
    }

    return j==substSize;
}

int main(){
    int qtde;
    cin >> qtde;

    while(qtde){
        int queries;
        string palavra;
        cin >> palavra;
        cin >> queries;

        while(queries){
            string subst;
            cin >> subst;

            if(temSubsequencia(palavra, subst)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }

            queries--;
        }
        qtde--;
    }

    return 0;
}
