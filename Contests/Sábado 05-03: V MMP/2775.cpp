/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num_pacotes, custo_total, aux;
    bool trocado;
    vector<int> pacotes, custos;

    while(cin >> num_pacotes){
        pacotes.resize(num_pacotes);
        custos.resize(num_pacotes);

        for(int i = 0; i < num_pacotes; i++){
            cin >> pacotes[i];
        }
        for(int i = 0; i < num_pacotes; i++){
            cin >> custos[i];
        }

        custo_total = 0;
        for(int i = 0; i < num_pacotes-1; i++){
            trocado = false;

            for(int j = 0; j < num_pacotes-1; j++){
                if(pacotes[j] > pacotes[j+1]){
                    custo_total += custos[j] + custos[j+1];
                    trocado = true;

                    aux = pacotes[j];
                    pacotes[j] = pacotes[j+1];
                    pacotes[j+1] = aux;

                    aux = custos[j];
                    custos[j] = custos[j+1];
                    custos[j+1] = aux;
                }
            }

            if(!trocado){
                break;
            }
        }

        cout << custo_total << '\n';
    }

    return 0;
}
