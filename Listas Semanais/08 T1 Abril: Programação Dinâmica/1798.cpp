/*
    Aluno:  Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int numPedidos, tamCano;
    cin >> numPedidos >> tamCano;
    
    vector<pair<int, int>> pedacos;
    
    for(int i=0; i<numPedidos; i++){
        int comprimento, valor;
        cin >> comprimento >> valor;

        if(comprimento <= tamCano){
            pedacos.push_back({comprimento, valor});
        }
    }
    
    vector<int> dp(tamCano+1, 0);
    
    for(int compAtual=1; compAtual<=tamCano; compAtual++) {
        int maxValor = dp[compAtual];

        for (auto& pedaco : pedacos) {
            int comp = pedaco.first;
            int val = pedaco.second;

            if(comp <= compAtual){
                int valorCalculado = dp[compAtual - comp] + val;

                if(valorCalculado > maxValor){
                    maxValor = valorCalculado;
                }
            }
        }
        dp[compAtual] = maxValor;
    }
    
    cout << dp[tamCano] << endl;
    
    return 0;
}