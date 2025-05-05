/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A + B <= C || A + C <= B || B + C <= A) {
        std::cout << "n\n";
        return 0;
    }

    int a = A, b = B, c = C;
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);

    if (a * a + b * b == c * c) {
        std::cout << "r\n";
    } else if (a * a + b * b > c * c) {
        std::cout << "a\n";
    } else {
        std::cout << "o\n";
    }

    return 0;
}