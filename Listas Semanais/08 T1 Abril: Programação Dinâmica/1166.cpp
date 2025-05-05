/*
    Aluno:  Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int varetas;
        int bolas = 1;
        cin >> varetas;

        vector<vector<int>> matriz(varetas);

        while(true){
            bool colocou = false;

            for(int i=0; i<varetas; i++){
                if(!matriz[i].empty()){
                    int soma = matriz[i].back() + bolas;
                    int raizQuad = sqrt(soma);

                    if(raizQuad*raizQuad == soma){
                        matriz[i].push_back(bolas);
                        colocou = true;
                        break;
                    }
                }
                else{
                    matriz[i].push_back(bolas);
                    colocou = true;
                    break;
                }
            }
            if(!colocou){
                break;
            }
            bolas++;
        }
        cout << bolas-1 << endl;
    }
}