/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio RIttershaussen Novaes
*/

#include <iostream>

bool ehNumero(std::string num){
    for(int i=0; i<num.length(); i++){
        if(!isdigit(num[i])){
            return false;
        }
    }
    return true;
}

int main(){
    std::string exp;

    while(std::cin >> exp){
        std::string membro1 = exp.substr(0, exp.find("+"));
        std::string membro2 = exp.substr(exp.find("+")+1, exp.find("=")-exp.find("+")-1);
        std::string membro3 = exp.substr(exp.find("=")+1, exp.length());

        if(ehNumero(membro1) && ehNumero(membro2)){
            std::cout << std::stoi(membro1) +std::stoi(membro2) << std::endl;
        }
        else if(ehNumero(membro1) && ehNumero(membro3)){
            std::cout << std::stoi(membro3) -std::stoi(membro1) << std::endl;
        }
        else{
            std::cout << std::stoi(membro3) -std::stoi(membro2) << std::endl;
        }

    }
    
    return 0;
}