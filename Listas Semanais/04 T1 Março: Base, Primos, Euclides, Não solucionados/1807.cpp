/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> calcularDivisores(int n){
    vector<int> res(n+1, 1);
    for(int i=2; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            res[j]++;
        }
    }
    return res;
}

long long expMod(long long base, long long exp, int mod) {
    long long resultado = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1){
            resultado = (resultado * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return resultado;
}

int main(){
    int r;
    cin >> r;

    long long res = expMod(3, r, pow(2,31)-1);
    
    cout << res << endl;
}