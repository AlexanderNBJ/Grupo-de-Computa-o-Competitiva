/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>

int main() {

	int tamanho;
	std::cin >> tamanho;

	int vetor[tamanho];
	int soma_total = 0;

	for(int i = 0; i < tamanho; i++){
		
		std::cin >> vetor[i];
		soma_total += vetor[i];
		
	} 

int soma_a = 0;
	for(int i = 0; i < tamanho; i++){
	
		soma_a += vetor[i];
		
		
		if(soma_a == soma_total/2){

		std::cout << i+1 << std::endl;
			return 0;
		}

	}

	return 0;

}