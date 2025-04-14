/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen
*/
#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int T, V, total = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> T >> V;
        total += T * V;
    }
    std::cout << total << std::endl;
    return 0;
}