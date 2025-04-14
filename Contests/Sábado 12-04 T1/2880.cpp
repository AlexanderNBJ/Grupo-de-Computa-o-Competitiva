/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <string>

int main()
{

    std::string mensagem;
    std::string crib;

    std::cin >> mensagem >> crib;
    int quantidade = 0;

    for (int i = 0; i <= mensagem.size() - crib.size(); i++)
    {

        bool possível = false;

        if (mensagem[i] != crib[0])
        {

            possível = true;

            for (int j = 0; j < crib.size(); j++)
            {
                if (mensagem[i + j] == crib[j])
                {
                    possível = false;
                    break;
                }
            }

            if (possível)
            {
                quantidade++;
            }
        }
    }

    std::cout << quantidade << std::endl;

    return 0;
}