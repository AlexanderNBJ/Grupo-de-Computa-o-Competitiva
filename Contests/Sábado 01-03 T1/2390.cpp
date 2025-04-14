/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen
*/
#include <iostream>

int main() {
    int N, T;
    std::cin >> N;

    int tempo_ligada = 0;
    int inicio_intervalo = 0;
    int fim_intervalo = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> T;

        if (T > fim_intervalo) {
            tempo_ligada += fim_intervalo - inicio_intervalo;
            inicio_intervalo = T;
            fim_intervalo = T + 10;
        } else {
            fim_intervalo = T + 10;
        }
    }

    tempo_ligada += fim_intervalo - inicio_intervalo;

    std::cout << tempo_ligada << std::endl;

    return 0;
}