/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    POLÍGONO
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int palitos;
    vector<int> medidas;

    cin >> palitos;

    for(int i=0; i<palitos; i++){
        int tmp;
        cin >> tmp;
        medidas.push_back(tmp);
    }

    sort(medidas.begin(), medidas.end());

    double soma =0;
    int resposta = 0;

    for(int i=0; i<palitos; i++){
        if(i>1 && soma>medidas[i]){
            resposta = i+1;
        }
        soma+=medidas[i];
    }

    cout << resposta << endl;

    return 0;
}