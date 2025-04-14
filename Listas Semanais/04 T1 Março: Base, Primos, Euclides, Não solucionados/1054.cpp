/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct Pedra{
    char tipo;
    int posicao;
};

int main(){
    int numeroCasos;
    cin >> numeroCasos;

    for(int casoAtual = 1; casoAtual <= numeroCasos; ++casoAtual){
        int nPedras, distancia;
        cin >> nPedras >> distancia;

        vector<Pedra> pedras(nPedras);

        for(int i = 0; i < nPedras; i++){
            string entrada;
            cin >> entrada;
            pedras[i].tipo = entrada[0];
            pedras[i].posicao = stoi(entrada.substr(2));
        }


        sort(pedras.begin(), pedras.end(), [](const Pedra &a, const Pedra &b){return a.posicao < b.posicao;});

        int baixa = 0, alta = distancia, resposta = distancia;

        while(baixa <= alta){
            int meio = (baixa + alta) / 2;
            set<int> usadasNaIda;
            int posicaoAtual = 0, indiceAtual = 0;
            bool possivelAvanco = true;


            while(true){
                if(posicaoAtual + meio >= distancia)
                    break;
                int alcanceMaximo = posicaoAtual + meio;
                int maisDistanteGrande = -1, indiceMaisDistanteGrande = -1;
                int maisDistantePequena = -1, indiceMaisDistantePequena = -1;

                for(int i = indiceAtual; i < pedras.size(); i++){
                    if(pedras[i].posicao > alcanceMaximo)
                        break;
                    if(pedras[i].tipo == 'B'){
                        if(pedras[i].posicao > maisDistanteGrande){
                            maisDistanteGrande = pedras[i].posicao;
                            indiceMaisDistanteGrande = i;
                        }
                    }
                    else{
                        if(pedras[i].posicao > maisDistantePequena){
                            maisDistantePequena = pedras[i].posicao;
                            indiceMaisDistantePequena = i;
                        }
                    }
                }

                if(maisDistanteGrande != -1){
                    posicaoAtual = maisDistanteGrande;
                    indiceAtual = indiceMaisDistanteGrande + 1;
                }

                else if(maisDistantePequena != -1){
                    posicaoAtual = maisDistantePequena;
                    usadasNaIda.insert(indiceMaisDistantePequena);
                    indiceAtual = indiceMaisDistantePequena + 1;
                }
                else{
                    possivelAvanco = false;
                    break;
                }
            }

            if(!possivelAvanco || (posicaoAtual + meio < distancia)){
                baixa = meio + 1;
                continue;
            }

            int posicaoAtualVolta = distancia, indiceAtualVolta = pedras.size() - 1;
            bool possivelVolta = true;

            while(true){
                if(posicaoAtualVolta - meio <= 0)
                    break;
                int alcanceMinimo = posicaoAtualVolta - meio;
                int maisDistanteGrandeVolta = -1, indiceMaisDistanteGrandeVolta = -1;
                int maisDistantePequenaVolta = -1, indiceMaisDistantePequenaVolta = -1;

                for(int i = indiceAtualVolta; i >= 0; i--){
                    if(pedras[i].posicao < alcanceMinimo)
                        break;
                    if(pedras[i].tipo == 'B'){
                        if(pedras[i].posicao > maisDistanteGrandeVolta){
                            maisDistanteGrandeVolta = pedras[i].posicao;
                            indiceMaisDistanteGrandeVolta = i;
                        }
                    }
                    else{
                        if(usadasNaIda.find(i) == usadasNaIda.end()){
                            if(pedras[i].posicao > maisDistantePequenaVolta){
                                maisDistantePequenaVolta = pedras[i].posicao;
                                indiceMaisDistantePequenaVolta = i;
                            }
                        }
                    }
                }

                if(maisDistanteGrandeVolta != -1){
                    posicaoAtualVolta = maisDistanteGrandeVolta;
                    indiceAtualVolta = indiceMaisDistanteGrandeVolta - 1;
                }
                else if(maisDistantePequenaVolta != -1){
                    posicaoAtualVolta = maisDistantePequenaVolta;
                    indiceAtualVolta = indiceMaisDistantePequenaVolta - 1;
                }
                else{
                    possivelVolta = false;
                    break;
                }
            }

            if(!possivelVolta || (posicaoAtualVolta - meio > 0)){
                baixa = meio + 1;
            }
            else{
                resposta = meio;
                alta = meio - 1;
            }
        }

        cout << "Case " << casoAtual << ": " << resposta << endl;
    }

    return 0;
}

