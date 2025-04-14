/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    while(!(n==0 && m==0)){
        vector<int> p(n);

        for(int i=0; i<n; i++){
            cin >> p[i];
            p[i]--;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string textoCifrado;
        getline(cin, textoCifrado);
        textoCifrado.resize(n, ' ');
        
        vector<int> q(n);
        for(int i=0; i<n; i++){
            q[p[i]] = i;
        }
        
        vector<bool> visitado(n, false);
        vector<int> resultado(n);
        
        for(int i=0; i<n; i++){
            if(!visitado[i]){
                vector<int> ciclo;
                int atual = i;

                while(true){
                    ciclo.push_back(atual);
                    visitado[atual] = true;
                    atual = q[atual];

                    if(atual == i){
                        break;
                    }
                }
                
                int tamanhoCiclo = ciclo.size();
                
                for(int j=0; j<tamanhoCiclo; j++) {
                    int passos = m % tamanhoCiclo;
                    int novaPos = (j + passos) % tamanhoCiclo;
                    resultado[ciclo[j]] = ciclo[novaPos];
                }
            }
        }
        
        string textoDecifrado(n, ' ');
        for (int i = 0; i < n; i++) {
            textoDecifrado[i] = textoCifrado[resultado[i]];
        }
        
        cout << textoDecifrado << endl;
        cin >> n >> m;
    }
    return 0;
}