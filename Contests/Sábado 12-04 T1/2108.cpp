/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string frase;
    string maiorPalavra = "";

    while(getline(cin, frase), frase != "0"){
        vector<string> palavras;
        stringstream ss(frase);
        string palavra;

        while(ss >> palavra){
            palavras.push_back(palavra);

            if(palavra.length()>=maiorPalavra.length()){
                maiorPalavra = palavra;
            }
        }

        for(int i=0; i<palavras.size(); i++){
            if(i==palavras.size()-1){
                cout << palavras[i].length() << endl;
            }
            else{
                cout << palavras[i].length() << "-";
            }
        }
    }
    cout <<"\nThe biggest word: "<<maiorPalavra << endl;
}