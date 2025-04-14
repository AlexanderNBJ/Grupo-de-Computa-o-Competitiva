/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int proximoPulo(int i){
    return 2*i -1;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> pedrasParaPular;
    vector<int> pedrasAtuais;
    pedrasAtuais.push_back(1);
    int pulo = 2;

    while(!(n ==0 && m==0)){
        for(int i : pedrasAtuais){
            if(i+proximoPulo(pulo) < n+1){
                pedrasParaPular.push_back(i+proximoPulo(pulo));
            }
            if(i-proximoPulo(pulo) > 0){
                pedrasParaPular.push_back(i-proximoPulo(pulo));
            }
            pulo = (i+proximoPulo(pulo) < n+1 || i-proximoPulo(pulo) > 0) ? pulo+1 : pulo;
        }

        pedrasAtuais.clear();

        if(!pedrasParaPular.empty()){
            for(int i : pedrasParaPular){
                if(i == m){
                    cout << "Let me try!" << endl;
                    pulo = 2;
                    cin >> n >> m;
                    pedrasAtuais.clear();
                    pedrasAtuais.push_back(1);
                    break;
                }
                pedrasAtuais.push_back(i);
            }
            pedrasParaPular.clear();
        }
        else{
            cout << "Don't make fun of me!" << endl;
            cin >> n >> m;
            pulo = 2;
            pedrasParaPular.clear();
            pedrasAtuais.push_back(1);
        }
    }
}