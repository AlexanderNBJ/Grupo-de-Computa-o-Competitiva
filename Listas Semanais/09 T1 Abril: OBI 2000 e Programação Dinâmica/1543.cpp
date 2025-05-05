/*
    Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int linhas, colunas;

    while (cin >> linhas >> colunas, linhas || colunas) {
        vector<vector<int>> matriz(linhas, vector<int>(colunas));

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cin >> matriz[i][j];
            }
        }

        int qtdPadroes;
        cin >> qtdPadroes;

        vector<string> padroes(qtdPadroes);
        for (int i = 0; i < qtdPadroes; i++) {
            cin >> padroes[i];
        }

        vector<vector<int>> pontuacao(linhas, vector<int>(qtdPadroes));

        for (int i = 0; i < linhas; i++) {
            for (int p = 0; p < qtdPadroes; p++) {
                int soma = 0;
                for (int j = 0; j < colunas; j++) {
                    if (padroes[p][j] == '+') {
                        soma += matriz[i][j];
                    } else if (padroes[p][j] == '-') {
                        soma -= matriz[i][j];
                    }
                }
                pontuacao[i][p] = soma;
            }
        }

        vector<vector<bool>> ehCompativel(qtdPadroes, vector<bool>(qtdPadroes, true));

        for (int a = 0; a < qtdPadroes; a++) {
            for (int b = 0; b < qtdPadroes; b++) {
                bool possivel = true;
                for (int j = 0; j < colunas; j++) {
                    char ca = padroes[a][j];
                    char cb = padroes[b][j];
                    if ((ca == '+' && cb == '+') || (ca == '-' && cb == '-')) {
                        possivel = false;
                        break;
                    }
                }
                ehCompativel[a][b] = possivel;
            }
        }

        if (linhas == 0) {
            cout << 0 << endl;
            continue;
        }

        vector<int> dpAnterior = pontuacao[0];

        for (int i = 1; i < linhas; i++) {
            vector<int> dpAtual(qtdPadroes, INT_MIN);

            for (int atual = 0; atual < qtdPadroes; atual++) {
                int melhorAnterior = INT_MIN;

                for (int anterior = 0; anterior < qtdPadroes; anterior++) {
                    if (ehCompativel[anterior][atual]) {
                        melhorAnterior = max(melhorAnterior, dpAnterior[anterior]);
                    }
                }

                if (melhorAnterior != INT_MIN) {
                    dpAtual[atual] = melhorAnterior + pontuacao[i][atual];
                }
            }

            dpAnterior = dpAtual;
        }

        cout << *max_element(dpAnterior.begin(), dpAnterior.end()) << endl;
    }

    return 0;
}

