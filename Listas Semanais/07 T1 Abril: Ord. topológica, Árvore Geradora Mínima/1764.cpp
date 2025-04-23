/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calcularMST(vector<vector<pair<int, int>>>& listaAdj, int numCidades) {
    vector<int> chave(numCidades, INT_MAX);
    vector<bool> visitado(numCidades, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;

    chave[0] = 0;
    filaPrioridade.push({0, 0});

    ll somaTotal = 0;

    while(!filaPrioridade.empty()){
        int noAtual = filaPrioridade.top().second;
        filaPrioridade.pop();

        if(visitado[noAtual]){
            continue;
        }
        else{
            visitado[noAtual] = true;
            somaTotal += chave[noAtual];
        }

        for(auto& aresta : listaAdj[noAtual]){
            int vizinho = aresta.first;
            int pesoAresta = aresta.second;
            
            if(!visitado[vizinho] && pesoAresta < chave[vizinho]){
                chave[vizinho] = pesoAresta;
                filaPrioridade.push({chave[vizinho], vizinho});
            }
        }
    }

    return somaTotal;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCidades, numCaminhos;

    while(cin >> numCidades >> numCaminhos && (numCidades || numCaminhos)){
        vector<vector<pair<int, int>>> listaAdj(numCidades);

        for(int i = 0; i < numCaminhos; ++i){
            int origem, destino, distancia;
            cin >> origem >> destino >> distancia;
            listaAdj[origem].emplace_back(destino, distancia);
            listaAdj[destino].emplace_back(origem, distancia);
        }

        cout << calcularMST(listaAdj, numCidades) << endl;
    }

    return 0;
}