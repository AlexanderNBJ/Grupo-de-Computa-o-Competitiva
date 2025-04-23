/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <bits/stdc++.h>
using namespace std;

int numeroVertices, numeroArestas;
vector<vector<int>> listaAdj;
vector<int> indices, lowLink, idComponente, pilha;
vector<bool> estaNaPilha;
int indiceAtual, numeroComponentes;

void tarjanDfs(int vertice){
    indices[vertice]=lowLink[vertice]=++indiceAtual;
    pilha.push_back(vertice);
    estaNaPilha[vertice]=true;

    for(int vizinho: listaAdj[vertice]){
        if(indices[vizinho]==0){
            tarjanDfs(vizinho);

            if(lowLink[vizinho]<lowLink[vertice]){
                lowLink[vertice]=lowLink[vizinho];
            }
        }
        else if(estaNaPilha[vizinho]){
            if(indices[vizinho]<lowLink[vertice]){
                lowLink[vertice]=indices[vizinho];
            }
        }
    }
    if(lowLink[vertice]==indices[vertice]){
        numeroComponentes++;

        while(true){
            int vTopo=pilha.back();
            pilha.pop_back();
            estaNaPilha[vTopo]=false;
            idComponente[vTopo]=numeroComponentes;

            if(vTopo==vertice){
                break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        cin>>numeroVertices;

        if(numeroVertices==0){
            break;
        }

        cin>>numeroArestas;
        listaAdj.assign(numeroVertices+1, vector<int>());

        for(int i=0;i<numeroArestas;i++){
            int origem,destino;
            cin>>origem>>destino;
            listaAdj[origem].push_back(destino);
        }

        indices.assign(numeroVertices+1,0);
        lowLink.assign(numeroVertices+1,0);
        idComponente.assign(numeroVertices+1,0);
        estaNaPilha.assign(numeroVertices+1,false);
        pilha.clear();
        indiceAtual=0;
        numeroComponentes=0;

        for(int v=1;v<=numeroVertices;v++){
            if(indices[v]==0){
                tarjanDfs(v);
            }
        }

        vector<int> grauSaida(numeroComponentes+1,0);

        for(int u=1;u<=numeroVertices;u++){
            for(int v: listaAdj[u]){
                if(idComponente[u]!=idComponente[v]){
                    grauSaida[idComponente[u]]++;
                }
            }
        }
        vector<int> resultado;

        for(int v=1;v<=numeroVertices;v++){
            if(grauSaida[idComponente[v]]==0){
                resultado.push_back(v);
            }
        }
        
        sort(resultado.begin(),resultado.end());

        for(int i=0;i<resultado.size();i++){
            if(i>0){
                cout<<' ';
            }
            cout<<resultado[i];
        }
        cout<<"\n";
    }
    return 0;
}
