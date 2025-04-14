/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool ehPrimo(int x){
    if(x == 2){
        return true;
    }
    else if(x <= 1 || x%2 == 0){
        return false;
    }
    else{
        for(int i=3; i<=sqrt(x); i+=2){
            if(x%i == 0){
                return false;
            }
        }
    }
    
    return true;
}

long long combinacao(int n, int k) {
    if (k < 0 || k > n){
        return 0;
    } 
    if (k == 0 || k == n){
        return 1;
    } 

    k = min(k, n-k); 
    long long res = 1;
    
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    while(n!=0 && m!=0 && k!=0){
        vector<int> contLinha(n, 0);
        vector<int> contColuna(m, 0);
        long long qtde = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int elem = i*m + j;

                if(!ehPrimo(elem)){
                    contLinha[i]++;
                    contColuna[j]++;
                }
            }
        }
        if(k == 1){
            int qtdeNaoPrimos = 0;
            for(int i: contLinha){
                qtdeNaoPrimos+=i;
            }
            printf("%d\n", qtdeNaoPrimos);
        }
        else{
            for(int i: contLinha){
                qtde+=combinacao(i, k);
            }
            for(int j: contColuna){
                qtde+=combinacao(j, k);
            }
            printf("%lld\n", qtde);
        }
        scanf("%d %d %d", &n, &m, &k);
    }
}