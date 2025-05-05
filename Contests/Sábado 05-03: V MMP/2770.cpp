/*
    Aluno:  Alexander Neves Barbosa Junior
            Arthur de Almeida Secundino
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>

using namespace std;

int main(){
    int x_empresa, y_empresa, num_pedidos, x_cliente, y_cliente;

    while(cin >> x_empresa >> y_empresa >> num_pedidos){
        for(int i = 0; i < num_pedidos; i++){
            cin >> x_cliente >> y_cliente;

            if((x_cliente <= x_empresa && y_cliente <= y_empresa)
            || (x_cliente <= y_empresa && y_cliente <= x_empresa)){
                cout << "Sim\n";
            }
            else{
                cout << "Nao\n";
            }
        }
    }

    return 0;
}
