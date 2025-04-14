/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/
#include <iostream>
#include <string>
using namespace std;

int main (){

string lista_amigos;
getline(cin, lista_amigos);

string novos_amigos;
getline(cin, novos_amigos);

string recomendacao; 
getline(cin, recomendacao);

size_t found = lista_amigos.find(recomendacao);

if(recomendacao=="nao"){

	string resposta = lista_amigos.append(" ").append(novos_amigos);
	cout << resposta << endl;

}

else{

string lista_amigos_inicio = lista_amigos.substr(0, found);

string lista_amigos_fim = lista_amigos.substr(found);


string resposta = lista_amigos_inicio.append(novos_amigos).append(" ").append(lista_amigos_fim);

cout << resposta << endl;

}



return 0;

}
