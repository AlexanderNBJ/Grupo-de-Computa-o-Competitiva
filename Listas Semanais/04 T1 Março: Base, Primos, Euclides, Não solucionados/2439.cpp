/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<vector<int>> gerarPadroes() {
    vector<vector<int>> padroes;
    for (int a = 0; a < 3; ++a)
        for (int b = 0; b < 3; ++b)
            for (int c = 0; c < 3; ++c)
                if (a != b && b != c)
                    padroes.push_back({a, b, c});
    return padroes;
}

bool ehCompativel(const vector<int>& coluna1, const vector<int>& coluna2) {
    for (int i = 0; i < 3; ++i)
        if (coluna1[i] == coluna2[i]) return false;
    return true;
}

vector<vector<long long>> multiplicarMatriz(const vector<vector<long long>>& matrizA, const vector<vector<long long>>& matrizB) {
    int tamanho = matrizA.size();
    vector<vector<long long>> matrizResultado(tamanho, vector<long long>(tamanho));
    for (int i = 0; i < tamanho; ++i)
        for (int k = 0; k < tamanho; ++k)
            if (matrizA[i][k])
                for (int j = 0; j < tamanho; ++j)
                    matrizResultado[i][j] = (matrizResultado[i][j] + matrizA[i][k] * matrizB[k][j]) % MOD;
    return matrizResultado;
}

vector<vector<long long>> potenciaMatriz(vector<vector<long long>> base, long long expoente) {
    int tamanho = base.size();
    vector<vector<long long>> resultado(tamanho, vector<long long>(tamanho));
    for (int i = 0; i < tamanho; ++i) resultado[i][i] = 1;
    
    while (expoente > 0) {
        if (expoente % 2)
            resultado = multiplicarMatriz(resultado, base);
        base = multiplicarMatriz(base, base);
        expoente /= 2;
    }
    return resultado;
}

int main() {
    long long n;
    cin >> n;

    vector<vector<int>> padroes = gerarPadroes();
    int quantidadePadroes = padroes.size();

    vector<vector<long long>> matrizTransicao(quantidadePadroes, vector<long long>(quantidadePadroes));
    for (int i = 0; i < quantidadePadroes; ++i)
        for (int j = 0; j < quantidadePadroes; ++j)
            if (ehCompativel(padroes[i], padroes[j]))
                matrizTransicao[i][j] = 1;

    if (n == 1) {
        cout << quantidadePadroes << '\n';
        return 0;
    }

    auto matrizPotencia = potenciaMatriz(matrizTransicao, n - 1);

    vector<long long> vetorInicial(quantidadePadroes, 1);

    vector<long long> vetorFinal(quantidadePadroes);
    for (int i = 0; i < quantidadePadroes; ++i)
        for (int j = 0; j < quantidadePadroes; ++j)
            vetorFinal[i] = (vetorFinal[i] + matrizPotencia[i][j] * vetorInicial[j]) % MOD;

    long long total = 0;
    for (long long contagem : vetorFinal)
        total = (total + contagem) % MOD;

    cout << total << '\n';
    
    return 0;
}
