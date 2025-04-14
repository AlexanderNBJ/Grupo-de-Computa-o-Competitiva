/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Tarefa
{
    int lucro;
    int horas;
};

bool ordenar(const Tarefa &a, const Tarefa &b) { return (a.lucro > b.lucro); }

int main()
{

    int quantidadeTarefas;
    int quantidadeHoras;

    while (std::cin >> quantidadeTarefas >> quantidadeHoras)
    {

        int lucroTotal = 0;
        int lucro = 0;

        std::vector<Tarefa> tarefas(quantidadeTarefas);
        std::vector<bool> horas(quantidadeHoras + 1);

        for (int i = 0; i < quantidadeTarefas; i++)
        {

            std::cin >> tarefas[i].lucro >> tarefas[i].horas;
            lucroTotal += tarefas[i].lucro;
        }

        std::sort(tarefas.begin(), tarefas.end(), ordenar);

        for (int i = 0; i < quantidadeTarefas; i++)
        {
            for (int j = tarefas[i].horas; j >= 1; j--)
            {
                if (!horas[j])
                {
                    horas[j] = true;
                    lucro += tarefas[i].lucro;
                    break;
                }
            }
        }

        std::cout << (lucroTotal - lucro) << std::endl;
    }

    return 0;
}


