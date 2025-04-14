/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int calculaForca(std::string nome)
{

    int forca = 0;

    for (char atual : nome)
    {
        forca += int(atual);
    }

    return forca;
}

std::string encontrarEmpate(const std::vector<std::string> &estudantes, const std::vector<long long int> &forcas)
{
    int n = estudantes.size();

    int esquerda = 0, direita = n - 1;
    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        long long forcaA = 0;
        for (int i = 0; i <= meio; i++)
        {

            forcaA += forcas[i] * (meio - i + 1);
        }

        long long forcaB = 0;
        for (int i = meio + 1; i < n; i++)
        {
            forcaB += forcas[i] * (i - meio);
        }

        if (forcaA == forcaB)
        {
            return estudantes[meio];
        }
        else if (forcaA < forcaB)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return "Impossibilidade de empate.";
}

int main()
{

    int quantidade;

    while (std::cin >> quantidade && quantidade != 0)
    {
        std::string nome;
        int forca = 0;

        std::vector<std::string> alunos(quantidade);
        std::vector<long long int> forcas(quantidade);

        for (int i = 0; i < quantidade; i++)
        {

            std::cin >> alunos[i];

            forcas[i] = calculaForca(alunos[i]);
        }

        int meio = (alunos.size()) / 2;

        std::string resultado = encontrarEmpate(alunos, forcas);
        std::cout << resultado << std::endl;
    }
}


