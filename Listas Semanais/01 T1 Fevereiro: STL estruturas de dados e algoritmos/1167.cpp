#include <iostream>
using namespace std;

struct Crianca {
    std::string nome;
    int ficha;
    Crianca* proxima = nullptr;
    Crianca* anterior = nullptr;
};

void buscaVencedor(Crianca* primeiraCrianca) {
    Crianca* atual = primeiraCrianca;
    int fichaAtual = primeiraCrianca->ficha;
    Crianca* aSerEliminada = atual;
    int controle = 0;

    while (atual->proxima != atual) { 
        Crianca* aSerEliminada = atual;
        if (fichaAtual % 2 == 0) {
            for (int i = controle; i < fichaAtual; i++) {
                aSerEliminada = aSerEliminada->proxima;
            }
        } 
        else {
            for (int i = controle; i < fichaAtual; i++) {
                aSerEliminada = aSerEliminada->anterior;
            }
        }

        aSerEliminada->anterior->proxima = aSerEliminada->proxima;
        aSerEliminada->proxima->anterior = aSerEliminada->anterior;
        fichaAtual = aSerEliminada->ficha;
        atual = (fichaAtual % 2 == 0) ? aSerEliminada->proxima : aSerEliminada->anterior;
        controle = 1;
        delete aSerEliminada;
    }

    cout << "Vencedor(a): " << atual->nome << endl;
}

int main() {
    int qtdeCriancas;
    cin >> qtdeCriancas;

    while (qtdeCriancas != 0) {
        Crianca* primeiraCrianca = nullptr;
        Crianca* ultimaCrianca = nullptr;

        for (int i = 0; i < qtdeCriancas; i++) {
            Crianca* atual = new Crianca;
            cin >> atual->nome >> atual->ficha;

            if (primeiraCrianca == nullptr) {
                primeiraCrianca = atual;
                primeiraCrianca->proxima = primeiraCrianca;
                primeiraCrianca->anterior = primeiraCrianca;
                ultimaCrianca = primeiraCrianca;
            } 
            else {
                atual->proxima = ultimaCrianca;
                ultimaCrianca->anterior = atual;
                ultimaCrianca = atual;
            }

            if(i == qtdeCriancas-1){
                atual->anterior = primeiraCrianca;
                primeiraCrianca->proxima = atual;
            }
        }

        buscaVencedor(primeiraCrianca);
        cin >> qtdeCriancas;
    }

    return 0;
}