/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <map>
#include <cmath>
#include <climits>
using namespace std;

map<int, int> fatorar(int n){
    map<int, int> fatores;

    for(int i=2; i*i <= n; i++){
        while(n%i ==0){
            fatores[i]++;
            n /=i;
        }
    }
    if(n > 1){
        fatores[n]++;
    }
    
    return fatores;
}

int legendre(int a, int b){
    int count = 0;
    while(a>0){
        a /=b;
        count += a;
    }
    return count;
}

int main(){
    int n, b;

    while(cin >> n >> b){
        if(!n){
            cout << "0 1" << endl;
            continue;
        }
        
        map<int,int> fatores = fatorar(b);
        int tmp = INT_MAX;

        for(auto& p: fatores){
            int x = p.first;
            int y = p.second;

            int count = legendre(n, x);
            int aux = count/y;
            if(aux < tmp){
                tmp = aux;
            }
        }

        int zeros = 0;

        if(tmp < INT_MAX){
            zeros = tmp;
        }

        double logSoma = lgamma(n+1);
        double logB = log(b);

        int digitos = (logSoma/logB) + 1;

        cout << zeros << " " << digitos << endl;

    }
}