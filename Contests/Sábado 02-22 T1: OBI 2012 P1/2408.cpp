/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a >= b && a <= c) || (a >= c && a <= b)) {
        cout << a << std::endl;
    } else if ((b >= a && b <= c) || (b >= c && b <= a)) {
        cout << b << std::endl;
    } else {
        cout << c << std::endl;
    }

    return 0;
}