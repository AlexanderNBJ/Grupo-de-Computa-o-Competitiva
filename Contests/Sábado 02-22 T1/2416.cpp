/*
    Nomes:  Alexander Neves
            Davi Paulino
            Maurílio Rittershaussen
*/

#include <iostream>
using namespace std;

int main() {

	int pista, fixo, termino;

	std::cin >> pista >> fixo;
	
	if(pista >= fixo){
		
		std::cout << pista%fixo << std::endl;
	}
	
	else{

		std::cout << fixo%pista << std::endl;
	}
	
	return 0;
}