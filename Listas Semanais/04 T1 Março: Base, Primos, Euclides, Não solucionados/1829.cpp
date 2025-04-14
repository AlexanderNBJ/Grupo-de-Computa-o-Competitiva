/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool avaliar(unsigned long long n, unsigned long long a, unsigned long long b) {
    long double log_a = logl(static_cast<long double>(a));
    long double rhs = b * log_a;
    long double lhs;

    if (n<=20){
        lhs = 0.0L;
        for(unsigned long long i = 2; i <= n; ++i){
            lhs += logl(static_cast<long double>(i));
        }
    } 
    else{
        long double n_ld = static_cast<long double>(n);
        lhs = n_ld * logl(n_ld) - n_ld + 0.5L * logl(2.0L * M_PI * n_ld);
    }

    return lhs > rhs;
}

int main(){
    int casos;
    cin >> casos;
    int pedroVence =0, lucasVence=0;
    vector<string> rodadas;

    for(int i=0; i< casos; i++){
        string lucas, pedro;
        cin >> lucas >> pedro;

        unsigned long long base, exp, fatorial;
        base = stoull(lucas.substr(0, lucas.find('^')));
        exp = stoull(lucas.substr(lucas.find('^')+1, lucas.length()));
        fatorial = stoull(pedro.substr(0, pedro.length()-1));


        if(avaliar(fatorial, base, exp)){
            pedroVence++;
            rodadas.push_back("Rodada #" + to_string(i + 1) + ": Pedro foi o vencedor");
        }
        else{
            lucasVence++;
            rodadas.push_back("Rodada #" + to_string(i + 1) + ": Lucas foi o vencedor");
        }
    }

    if(pedroVence == lucasVence){
        cout << "A competicao terminou empatada!" << endl;
    }
    else if(pedroVence > lucasVence){
        cout << "Campeao: Pedro!" << endl;
    }
    else{
        cout << "Campeao: Lucas!" << endl;
    }

    for(const string& jogo: rodadas){
        cout << jogo << endl;
    }
}
