/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <unordered_set>
using namespace std;

string avaliaFrase(string frase){
    unordered_set<char> letras;

    for(char a: frase){
        if(a >= 'a' && a <= 'z'){
            letras.insert(a);
        }
    }

    int countLetras = letras.size();

    if(countLetras == 26){
        return "frase completa";
    }
    else if(countLetras >= 13 ){
        return "frase quase completa";
    }
    else{
        return "frase mal elaborada";
    }
}

int main(){
    int casos;
    cin >> casos;
    cin.ignore();

    while(casos--){
        string frase;
        getline(cin, frase);

        cout << avaliaFrase(frase) << endl;
    }

    return 0;
}