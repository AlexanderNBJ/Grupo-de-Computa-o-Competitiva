/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <iomanip>
#include <map>

int main(){
    int qtdeDeCasos;
    std::cin >> qtdeDeCasos;
    std::cin.ignore();
    std::cin.ignore();

    bool primeiroCaso = true;

    while(qtdeDeCasos--){
        int totalDeArvores = 0;
        std::string nomeDaArvore;
        std::map <std::string, int> arvores;

        while (std::getline(std::cin, nomeDaArvore) && !nomeDaArvore.empty()) {
            arvores[nomeDaArvore]++;
            totalDeArvores++;
        }
        
        if(!primeiroCaso){
            std::cout << "\n";
        }
        primeiroCaso = false;

        for(auto pair : arvores){
            std::cout << pair.first << " " << std::fixed << std::setprecision(4) 
            << (((double)pair.second) /totalDeArvores)*100 << std::endl;
        }
    }

    return 0;
}