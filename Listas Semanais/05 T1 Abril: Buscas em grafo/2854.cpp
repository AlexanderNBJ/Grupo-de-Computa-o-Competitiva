/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

class UnionFind
{

    std::unordered_map<std::string, std::string> familia;

public:
    std::string find(const std::string &i)
    {

        if (familia.find(i) == familia.end())
        {
            familia[i] = i;
            return i;
        }

        if (familia[i] != i)
        {
            familia[i] = find(familia[i]);
        }

        return familia[i];
    }

    void unite(const std::string &i, const std::string &j)
    {

        std::string irep = find(i);
        std::string jrep = find(j);

        if (irep != jrep)
        {
            familia[irep] = jrep;
        }
    }

    int quantidadeFamilias()
    {

        std::unordered_set<std::string> familias;
        for (auto &pessoa : familia)
        {

            familias.insert(find(pessoa.first));
        }

        return familias.size();
    }
};

int main()
{

    int quantidadePessoas, quantidadeRelacoes;
    std::cin >> quantidadePessoas >> quantidadeRelacoes;

    UnionFind uf;

    for (int i = 0; i < quantidadeRelacoes; i++)
    {

        std::string pessoaA, relacao, pessoaB;
        std::cin >> pessoaA >> relacao >> pessoaB;

        uf.unite(pessoaA, pessoaB);
    }

    std::cout << uf.quantidadeFamilias() << std::endl;
}
