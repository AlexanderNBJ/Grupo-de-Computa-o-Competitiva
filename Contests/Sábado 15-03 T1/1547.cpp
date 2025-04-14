/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int qtdeAlunos, numero;
        cin >> qtdeAlunos >> numero;

        int posMaisProximo = 0;
        int maisProximo = 101;
        bool achou = false;

        for(int i=0; i<qtdeAlunos; i++){
            int atual;
            cin >> atual;

            if(!achou){
                if(atual == numero){
                    posMaisProximo = i;
                    maisProximo = abs(numero-atual);
                    achou = true;
                }
                else if(abs(numero-atual) < maisProximo){
                    posMaisProximo = i;
                    maisProximo = abs(numero-atual);
                }
            }
            
        }
        cout << posMaisProximo+1 << endl;

    }

    return 0;
}