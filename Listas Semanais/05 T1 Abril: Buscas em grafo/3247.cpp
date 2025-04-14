/*
    Nomes:  Alexander Neves Barboas Junior
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

const long long MODULO = 2147483647;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> grade(n);
    for (int i = 0; i < n; i++) {
        cin >> grade[i];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0LL));
    dp[0][0] = 1LL;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grade[i][j] == '#') {
                dp[i][j] = 0LL;
                continue;
            }
            if (i > 0 && grade[i-1][j] != '#') {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MODULO;
            }
            if (j > 0 && grade[i][j-1] != '#') {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MODULO;
            }
        }
    }
    
    if (dp[n-1][n-1] > 0) {
        cout << dp[n-1][n-1] % MODULO << "\n";
        return 0;
    }
    
    vector<vector<bool>> visitado(n, vector<bool>(n, false));
    queue<pair<int, int>> fila;
    
    int direcoes[4][2] = {
        {-1, 0},
        { 1, 0},
        { 0,-1},
        { 0, 1}
    };
    
    fila.push({0,0});
    visitado[0][0] = true;
    
    while (!fila.empty()) {
        auto linhaAtual = fila.front().first;
        auto colunaAtual = fila.front().second;
        fila.pop();
        
        if (linhaAtual == n-1 && colunaAtual == n-1) {
            cout << "THE GAME IS A LIE\n";
            return 0;
        }
        
        for (auto &d : direcoes) {
            int novaLinha = linhaAtual + d[0];
            int novaColuna = colunaAtual + d[1];
            
            if (novaLinha >= 0 && novaLinha < n &&
                novaColuna >= 0 && novaColuna < n) {
                
                if (!visitado[novaLinha][novaColuna] &&
                    grade[novaLinha][novaColuna] == '.') {
                    
                    visitado[novaLinha][novaColuna] = true;
                    fila.push({novaLinha, novaColuna});
                }
            }
        }
    }
    
    cout << "INCONCEIVABLE\n";
    return 0;
}

