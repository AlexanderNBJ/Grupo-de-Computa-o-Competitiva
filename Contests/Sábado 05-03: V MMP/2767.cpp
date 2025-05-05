/*
    Alunos: Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m, k;

    while(cin >> n >> m >> k){
        vector<int> homens(n), mulheres(m);
        vector<long long> homensMultiplos(k, 0), mulheresMultiplas(k, 0);


        for(int i=0; i<n; i++){
            cin >> homens[i];
            homensMultiplos[homens[i] % k]++;
        }

        for(int i=0; i<m; i++){
            cin >> mulheres[i];
            mulheresMultiplas[mulheres[i] % k]++;
        }
    
        long long resposta = 0;

        for(int i=0; i<k; i++){
            int aux = (k-i)%k;
            resposta += homensMultiplos[i]*mulheresMultiplas[aux];
        }
        cout << resposta << endl;
    }
}
