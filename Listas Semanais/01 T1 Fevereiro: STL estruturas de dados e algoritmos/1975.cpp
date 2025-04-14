/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
	int quantidadePerolas;
	int quantidadeAlunos;
	int quantidadeRespostas;

	while (std::cin >> quantidadePerolas && quantidadePerolas != 0)
	{
		std::cin >> quantidadeAlunos;
		std::cin >> quantidadeRespostas;
		std::cin.ignore();

		std::set<std::string> perolas;
		std::vector<std::string> alunos;

		for (int i = 0; i < quantidadePerolas; i++)
		{
			std::string perolaAtual;
			std::getline(std::cin, perolaAtual);
			perolas.insert(perolaAtual);
		}

		std::map<std::string, int> listaAlunos;
		int maior = -1;

		for (int i = 0; i < quantidadeAlunos; i++)
		{
			std::string nome;
			std::getline(std::cin, nome);

			int perolasporAluno = 0;

			for (int j = 0; j < quantidadeRespostas; j++)
			{
				std::string respostaAtual;
				std::getline(std::cin, respostaAtual);

				if (perolas.find(respostaAtual) != perolas.end())
				{
					perolasporAluno++;
				}
			}

			listaAlunos.insert(std::pair<std::string, int>(nome, perolasporAluno));

			if (perolasporAluno > maior)
			{
				maior = perolasporAluno;
			}
		}

		for (const auto &condicao : listaAlunos)
		{
			if (condicao.second == maior)
			{
				alunos.push_back(condicao.first);
			}
		}

		for (size_t i = 0; i < alunos.size(); i++)
		{
			if (i != 0)
			{
				std::cout << ", ";
			}
			std::cout << alunos[i];
		}
		std::cout << std::endl;
	}
}
