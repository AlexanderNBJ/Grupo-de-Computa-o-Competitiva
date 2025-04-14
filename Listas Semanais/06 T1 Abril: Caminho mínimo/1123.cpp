/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c, k;

    while(cin >> n >> m >> c >> k, n || m || c || k){
        vector<vector<pair<int, int>>> grafo(n);

        for(int i = 0; i < m; i++){
            int u, v, p;
            cin >> u >> v >> p;
            grafo[u].emplace_back(v, p);
            grafo[v].emplace_back(u, p);
        }

        vector<vector<pair<int, int>>> grafoMod(n);

        for(int u = 0; u < n; u++){
            if(u < c){
                if(u == c - 1){
                    grafoMod[u].clear();
                }
                else{
                    bool encontrouProxima = false;
                    for(auto &estrada : grafo[u]){
                        int v = estrada.first;
                        int p = estrada.second;
                        if(v == u + 1){
                            grafoMod[u].emplace_back(v, p);
                            encontrouProxima = true;
                            break;
                        }
                    }
                }
            }
            else{
                grafoMod[u] = grafo[u];
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(u == c - 1){
                break;
            }

            if(d > dist[u]){
                continue;
            }

            for(auto &[v, p] : grafoMod[u]){
                if(dist[u] + p < dist[v]){
                    dist[v] = dist[u] + p;
                    pq.emplace(dist[v], v);
                }
            }
        }

        cout << dist[c - 1] << endl;
    }
}