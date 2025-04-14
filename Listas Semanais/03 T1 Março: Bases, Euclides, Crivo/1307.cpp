/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
using namespace std;

int binarioParaDecimal(string bin) {
    int decimal = 0, base = 1;
    int len = bin.length();

    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int MDC(int F1, int F2) {
    while(F2 != 0) {
        int temp = F2;
        F2 = F1 % F2;
        F1 = temp;
    }

    return F1;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string S1, S2;
        cin >> S1;
        cin >> S2;

        int valorS1 = binarioParaDecimal(S1);
        int valorS2 = binarioParaDecimal(S2);
        int resultado = MDC(valorS1, valorS2);

        if (resultado > 1) {
            cout << "Pair #" << i << ": All you need is love!" << endl;
        } else {
            cout << "Pair #" << i << ": Love is not all you need!" << endl;
        }
    }

    return 0;
}
