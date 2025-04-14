/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes

    COPA DO MUNDO
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> champs;
    
    char campeao = 'A';
    for(int i=0; i<8; i++){
        int x,y;
        cin >> x >> y;

        if(x>y){
            champs.push_back(campeao);
        }
        else{
            champs.push_back(campeao+1);
        }
       campeao+=2;
    }
    
    vector<char> champsQuartas;

    for(int i=0; i<4; i++){
        int x,y;
        cin >> x >> y;

        if(x>y){
            champsQuartas.push_back(champs[2*i]);
        }
        else{
            champsQuartas.push_back(champs[2*i+1]);
        }
    }

    champs.clear();

    for(int i=0; i<2; i++){
        int x,y;
        cin >> x >> y;

        if(x>y){
            champs.push_back(champsQuartas[2*i]);
        }
        else{
            champs.push_back(champsQuartas[2*i+1]);
        }
    }

    int x,y;
    cin >> x >> y;

    if(x>y){
        cout << champs[0] << endl;
    }
    else{
        cout << champs[1] << endl;
    }

    return 0;
}