/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
int main()
{

	long long seguidores_atuais;
	long long seguidores_minimos;

	std::cin >> seguidores_atuais >> seguidores_minimos;

	std::vector<int> dias;

	for (int i = 0; i < 30; i++)
	{

		int valor;
		std::cin >> valor;
		dias.push_back(valor);
	}

	int total_dias = 0;

	while (seguidores_atuais < seguidores_minimos)
	{

		double media = std::ceil(std::accumulate(dias.begin(), dias.end(), 0) / 30.0);

		seguidores_atuais += media;

		dias.erase(dias.begin());
		dias.push_back(media);

		total_dias++;
	}

	std::cout << total_dias << std::endl;
}
