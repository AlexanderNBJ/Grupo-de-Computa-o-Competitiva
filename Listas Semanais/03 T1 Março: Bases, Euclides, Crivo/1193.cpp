/*
Alexander Neves Barbosa Junior
Davi Paulino Laboissiere
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int binarioParaDecimal(char *bin) {
    int decimal = 0, base = 1;
    int len = strlen(bin);

    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

int hexadecimalParaDecimal(char *hex) {
    int decimal = 0, base = 1, len = strlen(hex);

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

void inverterString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void decimalParaBinario(int dec, char *bin) {
    int i = 0;
    while (dec > 0) {
        bin[i++] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    inverterString(bin);
}

void decimalParaHexadecimal(int dec, char *hex) {
    sprintf(hex, "%x", dec);
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        char X[33], tipo[4];
        cin >> X >> tipo;
        int valor;

        if (strcmp(tipo, "bin") == 0) {
            valor = binarioParaDecimal(X);
        } else if (strcmp(tipo, "dec") == 0) {
            valor = atoi(X);
        } else if (strcmp(tipo, "hex") == 0) {
            valor = hexadecimalParaDecimal(X);
        }

        cout << "Case " << i << ":\n";
        if (strcmp(tipo, "dec") != 0) cout << valor << " dec\n";
        if (strcmp(tipo, "hex") != 0) {
            char hex[10];
            decimalParaHexadecimal(valor, hex);
            cout << hex << " hex\n";
        }
        if (strcmp(tipo, "bin") != 0) {
            char bin[33] = "";
            decimalParaBinario(valor, bin);
            cout << bin << " bin\n";
        }
        cout << "\n";
    }
}
