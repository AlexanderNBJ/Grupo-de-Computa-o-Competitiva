/*
    Aluno: Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int caso = 1;

    while(cin >> n, n){
        int xSuperiorEsquerdo, ySuperiorEsquerdo, xInferiorDireito, yInferiorDireito;
        int limiteEsquerdo = -10000, limiteDireito = 10000;
        int limiteSuperior = 10000, limiteInferior = -10000;

        for (int i = 0; i < n; ++i) {
            cin >> xSuperiorEsquerdo >> ySuperiorEsquerdo >> xInferiorDireito >> yInferiorDireito;

            limiteEsquerdo = max(limiteEsquerdo, xSuperiorEsquerdo);
            limiteSuperior = min(limiteSuperior, ySuperiorEsquerdo);
            limiteDireito = min(limiteDireito, xInferiorDireito);
            limiteInferior = max(limiteInferior, yInferiorDireito);
        }

        cout << "Teste " << caso++ << "\n";
        if(limiteEsquerdo <= limiteDireito && limiteInferior <= limiteSuperior){
            cout << limiteEsquerdo << " " << limiteSuperior << " " << limiteDireito << " " << limiteInferior << "\n\n";
        } 
        else{
            cout << "nenhum\n\n";
        }
    }
}

