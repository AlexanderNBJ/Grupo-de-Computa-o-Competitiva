/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<pair<char,char>> trocas(n);

    for(int i=0; i<n; i++){
        char a, b;
        cin >> a >> b;

        trocas[i].first = a;
        trocas[i].second = b;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for(int i=0; i<m; i++){
        string frase;
        getline(cin, frase);
        for(char& c: frase){
            for(int j=0; j<n; j++){
                if(trocas[j].first == c){
                    c = trocas[j].second;
                }
                else if(trocas[j].second == c){
                    c = trocas[j].first;
                }
            }
        }
        cout << frase << endl;
    }
}