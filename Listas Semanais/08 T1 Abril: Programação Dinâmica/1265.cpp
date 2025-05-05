/*
    Aluno:  Alexander Neves Barbosa Junior
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;

    while(cin >> N >> Q && (N||Q)){
        vector<string> titulos(N);

        for(int i=0; i<N; i++){
            cin >> titulos[i];
        }
        vector<int> consultas(Q);

        for(int i=0; i<Q; i++){
            cin >> consultas[i];
        }

        for(int k:consultas){
            string resultado;

            if(N==1){
                resultado=titulos[0];
            }
            else{
                long long soma = 0,prodAtual = N;
                int L = 1;
                long long prox = L*prodAtual;

                while(soma+prox<k){
                    soma += prox;
                    L++;
                    prodAtual *= N;
                    prox = L*prodAtual;
                }

                long long resto = k-soma;
                long long index = (resto-1)/L;
                int charPos = (resto-1)%L;

                vector<int> digitos;
                long long temp = index;

                for(int i=0;i<L;++i){
                    digitos.push_back(temp%N);
                    temp/=N;
                }
                reverse(digitos.begin(),digitos.end());
                
                int charCode=digitos[charPos];
                resultado=titulos[charCode];
            }
            cout << resultado << endl;
        }
        cout << endl;
    }
}