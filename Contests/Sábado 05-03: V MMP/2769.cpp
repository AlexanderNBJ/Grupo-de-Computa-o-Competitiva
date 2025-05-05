/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> custo_etapas_linha1, custo_etapas_linha2, custo_transicao12, custo_transicao21; 
int custo_saida1, custo_saida2;

int pd(int etapa, int num_etapas, int linha, vector<vector<int>>& memo){
    if(linha == 1){
        if(etapa == num_etapas){
            return custo_saida1;
        }

        if(memo[etapa][0] != -1){
            return memo[etapa][0];
        }

        int custo_mesma_linha = custo_etapas_linha1[etapa] + pd(etapa+1, num_etapas, 1, memo);
        int custo_outra_linha = INT32_MAX;

        if(etapa != num_etapas-1){
            custo_outra_linha = custo_etapas_linha1[etapa] + custo_transicao12[etapa] + pd(etapa+1, num_etapas, 2, memo);
        }

        memo[etapa][0] = min(custo_mesma_linha, custo_outra_linha);
        return memo[etapa][0];
    }
    else{
        if(etapa == num_etapas){
            return custo_saida2;
        }

        if(memo[etapa][1] != -1){
            return memo[etapa][1];
        }

        int custo_mesma_linha = custo_etapas_linha2[etapa] + pd(etapa+1, num_etapas, 2, memo);
        int custo_outra_linha = INT32_MAX;

        if(etapa != num_etapas-1){
            custo_outra_linha = custo_etapas_linha2[etapa] + custo_transicao21[etapa] + pd(etapa+1, num_etapas, 1, memo);
        }

        memo[etapa][1] = min(custo_mesma_linha, custo_outra_linha);
        return memo[etapa][1];
    }
}

int main(){
    int num_etapas, custo_entrada1, custo_entrada2;

    while(cin >> num_etapas){
        custo_etapas_linha1.resize(num_etapas);
        custo_etapas_linha2.resize(num_etapas);
        custo_transicao12.resize(num_etapas-1);
        custo_transicao21.resize(num_etapas-1);

        cin >> custo_entrada1 >> custo_entrada2;
        for(int i = 0; i < num_etapas; i++){
            cin >> custo_etapas_linha1[i];
        }
        for(int i = 0; i < num_etapas; i++){
            cin >> custo_etapas_linha2[i];
        }

        for(int i = 0; i < num_etapas-1; i++){
            cin >> custo_transicao12[i];
        }
        for(int i = 0; i < num_etapas-1; i++){
            cin >> custo_transicao21[i];
        }
        cin >> custo_saida1 >> custo_saida2;

        vector<vector<int>> memo(num_etapas+1, vector<int>(2, -1));
        int custo_iniciar_linha1 = custo_entrada1 + pd(0, num_etapas, 1, memo);
        int custo_iniciar_linha2 = custo_entrada2 + pd(0, num_etapas, 2, memo);

        cout << min(custo_iniciar_linha1, custo_iniciar_linha2) << '\n';
    }

    return 0;
}
