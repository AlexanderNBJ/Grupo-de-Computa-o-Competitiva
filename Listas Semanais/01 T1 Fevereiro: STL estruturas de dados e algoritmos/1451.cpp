/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <list>
#include <string>

void verifica(int posInicial, const std::string& frase, std::list<char>& beiju, std::list<char>::iterator pos) {
    for (int i = posInicial; i < frase.size(); i++) {
        char caractere = frase[i];

        if (caractere == '[') {
            pos = beiju.begin();  
            
            for (int j = i + 1; j < frase.size(); j++) {
                if (frase[j] == ']') {  
                    verifica(j + 1, frase, beiju, beiju.end()); 
                    return;
                }
                beiju.insert(pos, frase[j]);  
            }
        } else if (caractere == ']') {
            pos = beiju.end(); 
        } else {
            beiju.insert(pos, caractere); 
        }
    }
}

int main() {
    std::string frase;

    while (std::getline(std::cin, frase)) {
        std::list<char> beiju; 
        std::list<char>::iterator pos = beiju.end();  

        for (const auto& caractere : frase) {
            if (caractere == '[') {
                pos = beiju.begin();  
            } else if (caractere == ']') {
                pos = beiju.end();  
            } else {
                beiju.insert(pos, caractere);  
            }
        }

        // Imprime o resultado final da linha
        for (const auto& caractere : beiju) {
            std::cout << caractere;
        }
        std::cout << std::endl;  
    }

    return 0;
}
