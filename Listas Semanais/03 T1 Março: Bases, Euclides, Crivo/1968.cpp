/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
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
    int a,b,n;
    cin >> a >> b >> n;

    int qtdeLideres = 0;
    vector<int> divisores = calcularDivisores(b);

    for(int i=a; i<=b; i++){
        if(divisores[i]==n){
            qtdeLideres++;
        }
    }
    int qtdeNaoLideres = b-a+1-qtdeLideres;
   
    if(!qtdeLideres){
        cout << 0 << endl;
    }
    else{
        cout << expMod(qtdeLideres, qtdeNaoLideres, 1e9 +7)<< endl;
    }
}