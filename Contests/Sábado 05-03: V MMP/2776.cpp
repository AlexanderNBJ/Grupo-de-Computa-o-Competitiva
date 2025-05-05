/*
    Alunos: Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;

    while(cin >> n >> m){
        vector<pair<int,int>> promocoes(n);
        vector<int> dp(m+1, -1);
        dp[0] = 0;

        for(int i=0; i<n; i++){
            cin >> promocoes[i].first >> promocoes[i].second;
        }

        for(int i=0; i<=m; i++){
            if(dp[i]== -1){
                continue;
            }
            else{
                for(auto[x, y]: promocoes){
                    if(i+x <=m){
                        dp[i+x] = max(dp[i+x], dp[i]+y);
                    }
                }
            }
        }
        cout << dp[m] << endl;
    }
}
