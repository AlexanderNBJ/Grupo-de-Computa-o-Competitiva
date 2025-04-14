/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>
using namespace std;

void contamina(vector<string>& mapa, int n, int m){
    bool mudou = true;

    while(mudou){
        mudou = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mapa[i][j] == 'T'){
                    for(int k=i+1; k<n&&(mapa[k-1][j]=='T'); k++){
                        if(mapa[k][j] == 'A'){
                            mapa[k][j] = 'T';
                            mudou = true;
                        }
                    }

                    for(int k=i-1; k>=0&&(mapa[k+1][j]=='T'); k--){
                        if(mapa[k][j] == 'A'){
                            mapa[k][j] = 'T';
                            mudou = true;
                        }
                    }

                    for(int k=j+1; k<m&&(mapa[i][k-1]=='T'); k++){
                        if(mapa[i][k] == 'A'){
                            mapa[i][k] = 'T';
                            mudou = true;
                        }
                    }

                    for(int k=j-1; k>=0&&(mapa[i][k+1]=='T'); k--){
                        if(mapa[i][k] == 'A'){
                            mapa[i][k] = 'T';
                            mudou = true;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    while(n!=0 || m!=0){
        vector<string> mapa (n);

        for(int i=0; i<n; i++){
            cin >> mapa[i];
        }
        
        contamina(mapa, n, m);

        for(int i=0; i<n; i++){
            cout << mapa[i] << endl;
        }
        cout << endl;

        cin >> n >> m;
    }
}


