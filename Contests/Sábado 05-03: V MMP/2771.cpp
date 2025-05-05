/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int qtd_notas, nota_procurada;
    cout << fixed << setprecision(1);

    while(cin >> qtd_notas >> nota_procurada){
        vector<int> notas(qtd_notas);
        vector<double> medias;

        for(int i = 0; i < qtd_notas; i++){
            cin >> notas[i];
        }

        for(int i = 0; i < qtd_notas; i++){
            for(int j = i+1; j < qtd_notas; j++){
                for(int k = j+1; k < qtd_notas; k++){
                    medias.push_back((notas[i] + notas[j] + notas[k]) / 3.0);
                }
            }
        }

        sort(medias.begin(), medias.end(), greater<double>());
        cout << medias[nota_procurada-1] << '\n';
    }

    return 0;
}
