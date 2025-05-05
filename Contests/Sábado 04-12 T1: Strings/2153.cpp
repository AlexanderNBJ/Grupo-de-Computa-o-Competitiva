/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>

std::string encontraRep(const std::string &palavra)
{
    int n = palavra.length();

    for (int i = 1; i < n; ++i)
    {
        std::string pref = palavra.substr(0, n - i);
        std::string suf = palavra.substr(n - i);

        if (pref.ends_with(suf))
        {
            return pref;
        }
    }

    return palavra;
}

int main()
{
    std::string palavra;

    while (std::cin >> palavra)
    {
        std::cout << encontraRep(palavra) << std::endl;
    }

    return 0;
}