/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PalavraCounter{
    int caractere;
    int count = 1;
};

bool ordenar(const PalavraCounter& a, const PalavraCounter& b) {
    if (a.count != b.count) {
        return a.count < b.count;
    }
    return a.caractere > b.caractere;
}

int main(){
    string palavra;
    vector<PalavraCounter> vetor;
    bool primeiro = true;

    while(cin >> palavra){
      for(int caractere : palavra){
        bool encontrou = false;
        for(PalavraCounter& a : vetor){
            if(a.caractere == caractere){
                a.count++;
                encontrou = true;
                break;
            }
        }
        if(!encontrou){
            PalavraCounter a;
            a.caractere = caractere;
            vetor.push_back(a);
        }
      }
      sort(vetor.begin(), vetor.end(), ordenar);

      if(!primeiro){
        cout << endl;
      }
      primeiro = false;

      for(PalavraCounter a : vetor){
        cout << a.caractere <<" "<< a.count << endl;
      }
      vetor.clear();
    }

    return 0;
}
