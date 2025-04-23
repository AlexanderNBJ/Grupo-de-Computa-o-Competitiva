/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int prim(vector<vector<int>> grafo, int n, int o){
    int qtdeArestas = 0, soma = 0;
    vector<bool> visitados (n, false);
    visitados[o] = true;

    while(qtdeArestas < n-1){
        int min = INT_MAX, x, y;

        for(int i=0; i<n; i++){
            if(visitados[i]){
                for(int j=0; j<n; j++){
                    if(!visitados[j] && grafo[i][j] && grafo[i][j]<min){
                        min = grafo[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        soma += min;
        visitados[y] = true;
        qtdeArestas++;
    }
    return 2*soma;
}

int main(){
    int n, m, o;
    cin >> n >> m >> o;

    vector<vector<int>> grafo (n, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        grafo[a][b] = grafo[b][a] = c;
    }
    cout << prim(grafo, n, o) << endl;
}