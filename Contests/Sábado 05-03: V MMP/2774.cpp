/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int horas, minutos, num_medidas;
    double media, soma, diferenca, precisao;
    cout << fixed << setprecision(5);

    while(cin >> horas >> minutos){
        num_medidas = horas * 60 / minutos;
        media = 0.0;

        double valores_medidos[num_medidas];
        for(int i = 0; i < num_medidas; i++){
            cin >> valores_medidos[i];
            media += valores_medidos[i];
        }
        media /= num_medidas;

        soma = 0.0;
        for(int i = 0; i < num_medidas; i++){
            diferenca = valores_medidos[i] - media;
            soma += diferenca * diferenca;
        }

        precisao = sqrt(soma / (num_medidas - 1));
        cout << precisao << '\n';
    }

    return 0;
}
