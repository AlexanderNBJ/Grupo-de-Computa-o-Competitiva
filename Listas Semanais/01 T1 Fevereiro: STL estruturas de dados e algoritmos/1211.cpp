/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    int quantidade;

    while (std::cin >> quantidade && quantidade != EOF) {
        std::cin.ignore();
	
	std::vector<std::string> listaTelefonica(quantidade);

        for (int i = 0; i < quantidade; i++) {
            std::getline(std::cin, listaTelefonica[i]);
        }

        std::sort(listaTelefonica.begin(), listaTelefonica.end());

        int total = 0;

        for (int i = 0; i < listaTelefonica.size() - 1; i++) {
            std::string telefone1 = listaTelefonica[i];
            std::string telefone2 = listaTelefonica[i+1];

            int contador = 0;
            for (int j = 0; j < telefone1.length(); j++) {
                if (telefone1[j] == telefone2[j]) {
                    contador++; 
                } else {
                    break;
                }
            }

            total += contador; 
        }

        std::cout << total << std::endl;
    }

    return 0;
}
