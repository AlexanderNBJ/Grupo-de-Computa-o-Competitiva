/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    SALDO DO VOVÔ
*/

#include <iostream>

int main()
{

    int quantidaeTransacoes;
    int saldo;
    int movimentacao;

    std::cin >> quantidaeTransacoes >> saldo;

    int menorValor = saldo;

    for (int i = 0; i < quantidaeTransacoes; i++)
    {

        std::cin >> movimentacao;
        saldo += movimentacao;

        if (saldo < menorValor)
        {
            menorValor = saldo;
        }
    }

    std::cout << menorValor << std::endl;

    return 0;
}