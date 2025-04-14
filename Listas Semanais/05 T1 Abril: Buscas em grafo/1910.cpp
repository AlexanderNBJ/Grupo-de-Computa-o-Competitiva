/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_CANAL = 100000;

int main() {

    int canalOrigem, canalDestino, qtdProibidos;
    cin >> canalOrigem >> canalDestino >> qtdProibidos;
    while(true) {
        if(canalOrigem == 0 && canalDestino == 0 && qtdProibidos == 0) break;
        
        vector<bool> canalProibido(MAX_CANAL + 1, false);
        for (int i = 0; i < qtdProibidos; i++) {
            int canal;
            cin >> canal;
            if(canal >= 0 && canal <= MAX_CANAL)
                canalProibido[canal] = true;
        }
        
        vector<int> dist(MAX_CANAL + 1, -1);
        
        queue<int> fila;
        fila.push(canalOrigem);
        dist[canalOrigem] = 0;
        
        while(!fila.empty()) {
            int canalAtual = fila.front();
            fila.pop();
            
            if(canalAtual == canalDestino) break;
            
            int proximosCanais[5];
            proximosCanais[0] = canalAtual + 1;
            proximosCanais[1] = canalAtual - 1;
            proximosCanais[2] = canalAtual * 2;
            proximosCanais[3] = canalAtual * 3;

            if(canalAtual % 2 == 0)
                proximosCanais[4] = canalAtual / 2;
            else
                proximosCanais[4] = -1;
            
            for (int i = 0; i < 5; i++) {
                int proximoCanal = proximosCanais[i];

                if(proximoCanal < 1 || proximoCanal > MAX_CANAL) continue;
                if(canalProibido[proximoCanal]) continue;

                if(dist[proximoCanal] == -1) {
                    dist[proximoCanal] = dist[canalAtual] + 1;
                    fila.push(proximoCanal);
                }
            }
        }
        
        cout << dist[canalDestino] << "\n";
        cin >> canalOrigem >> canalDestino >> qtdProibidos;
    }
    
    return 0;
}

