/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

string lowerCase(const string nome){
    string res = nome;
    for(char& c: res){
        c = toupper(c);
    }
    return res;
}

bool compara(const pair<string, string>& a, const pair<string, string>& b){
    return a.second < b.second;
}

int main(){
    string nome;
    vector<pair<string, string>> ordemAlfabetica;

    while(getline(cin, nome)){
        ordemAlfabetica.push_back({nome, lowerCase(nome)});
    }
    auto ulitm = max_element(ordemAlfabetica.begin(), ordemAlfabetica.end(), compara);
    cout << ulitm->first << endl;
}