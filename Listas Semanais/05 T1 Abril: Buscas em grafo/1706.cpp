/*
    Nomes:  Alexander Neves Barboas Junior
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;

    while (cin >> n >> m) {

        vector<vector<int>> grafo(n + 1);
        vector<char> notas(n);

        for (int i = 0; i < n; i++) {
            cin >> notas[i];
        }
        

        for (int i = 0; i < m; i++) {
            int torreA, torreB;
            cin >> torreA >> torreB;
            grafo[torreA].push_back(torreB);
            grafo[torreB].push_back(torreA);
        }
        
        
        vector<bool> visitado(n + 1, false);
        bool possivel = true;
        
        for (int i = 1; i <= n && possivel; i++) {
            if (!visitado[i]) {
                queue<int> fila;
                fila.push(i);
                visitado[i] = true;
                int somaB = 0;
                
                while (!fila.empty()) {
                    int atual = fila.front();
                    fila.pop();
                    
                    if (notas[atual - 1] == 'B') {
                        somaB++;
                    }

                    for (int vizinho : grafo[atual]) {
                        if (!visitado[vizinho]) {
                            visitado[vizinho] = true;
                            fila.push(vizinho);
                        }
                    }
                }

                if (somaB % 2 != 0) {
                    possivel = false;
                }
            }
        }
        
        cout << (possivel ? "Y" : "N") << "\n";
    }
    
    return 0;
}

