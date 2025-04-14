/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time {
    int indice = 0;
    int pontos = 0;
    int pontosMarcados = 0;
    int pontosRecebidos = 0;
};

bool ordena(const Time& a, const Time& b) {
    double cestaAverageA = (a.pontosRecebidos == 0) ? a.pontosMarcados : (double)a.pontosMarcados / a.pontosRecebidos;
    double cestaAverageB = (b.pontosRecebidos == 0) ? b.pontosMarcados : (double)b.pontosMarcados / b.pontosRecebidos;

    if (a.pontos != b.pontos){
        return a.pontos > b.pontos;
    }
    else if (cestaAverageA != cestaAverageB) {
        return cestaAverageA > cestaAverageB;
    }
    else if (a.pontosMarcados != b.pontosMarcados){
        return a.pontosMarcados > b.pontosMarcados; 
    }
    else{
        return a.indice < b.indice; 
    }
}

bool temTime(vector<Time> times, int indice) {
    for (Time t : times) {
        if (t.indice == indice) {
            return true;
        }
    }
    return false;
}

int main() {
    int qtdeTimes;
    int count = 1;

    while (cin >> qtdeTimes && qtdeTimes) {
        vector<Time> times;

        for (int i = 0; i < qtdeTimes*(qtdeTimes-1)/2; i++) {
            int x, y, w, z;
            cin >> x >> y >> w >> z;
            
            if(!temTime(times, x)){
                Time tmp;
                tmp.indice = x;
                times.push_back(tmp);
            }

            if(!temTime(times, w)){
                Time tmp;
                tmp.indice = w;
                times.push_back(tmp);
            }

            for(Time& t: times){
                if(t.indice == x){
                    t.pontosMarcados+=y;
                    t.pontosRecebidos+=z;
                }
                else if(t.indice == w){
                    t.pontosMarcados+=z;
                    t.pontosRecebidos+=y;
                }

                if(y > z){
                    if(t.indice == x){
                        t.pontos+=2;
                    }
                    else if(t.indice == w){
                        t.pontos++;
                    }
                }
                else if(y < z){
                    if(t.indice == x){
                        t.pontos++;
                    }
                    else if(t.indice == w){
                        t.pontos+=2;
                    }
                }
            }
        }

        sort(times.begin(), times.end(), ordena);

        if(count > 1){
            cout << endl;
        }

        cout << "Instancia " << count++ << endl;
        
        int n = times.size();
        for (int i = 0; i < n - 1; i++){
            cout << times[i].indice << " ";
        }
        cout << times[n - 1].indice << endl;
    }

    return 0;
}

