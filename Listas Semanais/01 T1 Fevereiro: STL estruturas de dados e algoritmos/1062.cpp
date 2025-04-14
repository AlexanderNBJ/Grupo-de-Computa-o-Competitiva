/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <stack>
#include <queue>

int main()
{
	int quantidade;

	while (std::cin >> quantidade && quantidade != 0)
	{

		while (true)
		{
			std::stack<int> estacao;
			std::stack<int> comboio;
			std::queue<int> sequencia;
			bool possivel = true;

			for (int i = quantidade; i >= 1; i--)
			{
				comboio.push(i);
			}

			int primeiroVagao;
			std::cin >> primeiroVagao;

			if (primeiroVagao == 0)
			{
				std::cout << std::endl;
				break;
			}

			sequencia.push(primeiroVagao);

			for (int i = 1; i < quantidade; i++)
			{
				int proximoVagao;
				std::cin >> proximoVagao;
				sequencia.push(proximoVagao);
			}

			while (!sequencia.empty())
			{
				if (!comboio.empty() && comboio.top() == sequencia.front())
				{

					comboio.pop();
					sequencia.pop();
				}
				else if (!estacao.empty() && estacao.top() == sequencia.front())
				{
					estacao.pop();
					sequencia.pop();
				}
				else if (comboio.empty() && !estacao.empty() && estacao.top() != sequencia.front())
				{
					possivel = false;
					break;
				}
				else
				{
					estacao.push(comboio.top());
					comboio.pop();
				}
			}

			if (possivel)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
			}
		}
	}

	return 0;
}
