/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

int hexadecimalParaDecimal(const string& hex) {
    int decimal = 0, base = 1, len = hex.length();

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}

void decimalParaHexadecimal(int dec, string& hex) {
    char buffer[33];
    sprintf(buffer, "0x%X", dec);
    hex = buffer;
}

int main() {
    string entrada;

    while (true) {
        cin >> entrada;
        if (entrada[0] == '-') {
            break;
        }
        bool ehHex = (entrada.length() > 1 && entrada[0] == '0' && entrada[1] == 'x') || 
                     (entrada.length() > 1 && entrada[1] == 'x');

        if (ehHex) {
            int decimal = hexadecimalParaDecimal(entrada.substr(2));
            cout << decimal << endl;
        } else {
            int decimal = atoi(entrada.c_str());
            string hex;
            decimalParaHexadecimal(decimal, hex);
            cout << hex << endl;
        }
    }

    return 0;
}
