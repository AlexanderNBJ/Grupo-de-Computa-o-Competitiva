/*
    Aluno: Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int jogos;
    int caso = 1;

    while(cin >> jogos, jogos){
        int melhorPrimeiro = 0, melhorUltimo = 0, melhorSaldo = 0;
        int primeiro = 1, saldo = 0;
        
        for(int i=1; i<=jogos; i++){
            int x, y;
            cin >> x >> y;
            saldo += x - y;

            // saldo negativo, reinicia o período
            if(saldo < 0){
                saldo = 0;
                primeiro = i+1;
            }
            else{
                // verifica se é melhor ou mesmo saldo mas intervalo maior
                if(saldo > melhorSaldo || (saldo == melhorSaldo && (i - primeiro > melhorUltimo - melhorPrimeiro)))
                {
                    melhorSaldo = saldo;
                    melhorPrimeiro = primeiro;
                    melhorUltimo = i;
                }
            }
        }

        cout << "Teste " << caso << endl;
        if(melhorSaldo > 0){
            cout << melhorPrimeiro << " " << melhorUltimo << endl;
        }
        else{
            cout << "nenhum" << endl;
        }
        cout << endl;
        caso++;
    }
}

