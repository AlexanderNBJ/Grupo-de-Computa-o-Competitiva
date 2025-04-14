/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	vector<string> joias;

	while (cin >> input)
	{

		if (find(joias.begin(), joias.end(), input) == joias.end())
		{
			joias.push_back(input);
		}
	}

	cout << joias.size() << endl;

	return 0;
}
