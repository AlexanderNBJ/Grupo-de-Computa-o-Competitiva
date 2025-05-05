/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    REUNIÃO
*/

#include <iostream>
#include <limits>
using namespace std;

int main(){
    int n,m;
    int inf = numeric_limits<int>::max();
    cin >> n >> m;

    int cidades[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cidades[i][j] = inf;
        }
    }

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        cidades[x][y] = z;
        cidades[y][x] = z;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (cidades[i][k] !=  inf && cidades[k][j] != inf && cidades[i][j] > cidades[i][k] + cidades[k][j]) {
                    cidades[i][j] = cidades[i][k] + cidades[k][j];
                }
            }
        }
    }

    int minMaxDist = inf;

    for(int i = 0; i < n; i++) {
        int maxDist = 0;

        for(int j = 0; j < n; j++) {
            if(cidades[i][j] > maxDist){
                maxDist = cidades[i][j];
            }
        }
        if(maxDist < minMaxDist){
            minMaxDist = maxDist;
        }
    }
    cout << minMaxDist << endl;
    return 0;
}