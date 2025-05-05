/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

string analisa(string frase){
    vector<bool> letras(26, false);

    for(char c: frase){
        if(c >= 'a' && c<='z'){
            letras[c-'a'] = true;
        }
    }
    int qtde = 0;

    for(int i=0; i<26; i++){
        if(letras[i])
            qtde++;
    }

    if(qtde==26){
        return "frase completa";
    }
    else if(qtde>=13){
        return "frase quase completa";
    }
    else{
        return "frase mal elaborada";
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        string frase;
        getline(cin, frase);
        cout << analisa(frase) << endl;
    }
}