/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<int>> listaAdj(n);
        vector<int> grauEntrada(n, 0);

        for (int i = 0; i < n; ++i) {
            int mi;
            cin >> mi;
            for (int j = 0; j < mi; ++j) {
                int dependencia;
                cin >> dependencia;
                dependencia--;
                listaAdj[dependencia].push_back(i);
                grauEntrada[i]++;
            }
        }

        queue<int> fila;
        vector<int> tempoCompilacao(n, 0);
        int arquivosProcessados = 0;
        int tempoTotal = 0;

        for (int i = 0; i < n; ++i) {
            if(grauEntrada[i] == 0){
                fila.push(i);
                tempoCompilacao[i] = 1;
            }
        }

        while(!fila.empty()){
            int atual = fila.front();
            fila.pop();
            arquivosProcessados++;
            tempoTotal = max(tempoTotal, tempoCompilacao[atual]);

            for(int vizinho : listaAdj[atual]){
                if(--grauEntrada[vizinho] == 0){
                    fila.push(vizinho);
                }
                if(tempoCompilacao[vizinho] < tempoCompilacao[atual] + 1){
                    tempoCompilacao[vizinho] = tempoCompilacao[atual] + 1;
                }
            }
        }

        if(arquivosProcessados != n){
            cout << -1 << endl;
        }
        else{
            cout << tempoTotal << endl;
        }
    }
    return 0;
}