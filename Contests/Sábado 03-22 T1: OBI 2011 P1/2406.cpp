/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string cadeia;
        cin >> cadeia;

        stack<char> pilha;
        bool valida = true;

        for (char caractere : cadeia) {
            if (caractere == '{' || caractere == '[' || caractere == '(') {
                pilha.push(caractere);
            } else {
                if (pilha.empty()) {
                    valida = false;
                    break;
                }
                char topo = pilha.top();
                pilha.pop();
                if ((caractere == '}' && topo != '{') ||
                    (caractere == ']' && topo != '[') ||
                    (caractere == ')' && topo != '(')) {
                    valida = false;
                    break;
                }
            }
        }

        if (valida && pilha.empty()) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}