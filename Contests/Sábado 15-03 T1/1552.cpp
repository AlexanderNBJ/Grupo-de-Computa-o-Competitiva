/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

struct Pessoa{
    int x,y;
};

double calculaDist(Pessoa p, Pessoa q){
    double posX = powf(p.x - q.x, 2);
    double posY = powf(p.y - q.y, 2);
    return sqrt(posX + posY);
}

double algoritmoDePrim(vector<Pessoa> malha){
    int tamanho = malha.size();
    double comprimentoTotal = 0;
    vector<double> dist(tamanho, INT_MAX);
    vector<bool> visitado(tamanho, false);
    dist[0] = 0;

    for (int i=0; i<tamanho; i++) {
        int u = -1;
        
        for (int j=0; j<tamanho; j++) {
            if (!visitado[j] && (u==-1 || dist[j]<dist[u])) {
                u = j;
            }
        }

        visitado[u] = true;
        comprimentoTotal += dist[u];

        for (int k=0; k<tamanho; k++) {
            if (!visitado[k]) {
                double d = calculaDist(malha[u], malha[k]);
                if (d<dist[k]) {
                    dist[k] = d;
                }
            }
        }
    }

    return comprimentoTotal;
}

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int qtdePessoas;
        cin >> qtdePessoas;

        vector<Pessoa> malhaPessoas;

        for(int i=0; i<qtdePessoas; i++){
            Pessoa p;
            cin >> p.x >> p.y;

            malhaPessoas.push_back(p);
        }
        cout << fixed << setprecision(2) <<  algoritmoDePrim(malhaPessoas)/100 << endl;
    }

    return 0;
}