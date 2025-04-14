/*
    Nomes:  Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculaBaseMaior(int b, int B, int H, double h){
    return b +((B-b)*h)/H;
}

double calculaVolume(int b, int B, int H, double h){
    double Bezao = calculaBaseMaior(b, B, H, h);
    return (M_PI*h*(Bezao*Bezao +b*b +Bezao*b))/3;
}

double calculaAltura(int b, int B, int H, double volume, double esq, double dir) {
    while(dir-esq > 1e-9){ 
        double meio = (esq+dir)/2;
        double fxi = calculaVolume(b, B, H, meio) -volume;

        if(fxi > 0){
            dir = meio;
        }
        else{
            esq = meio;
        }
    }
    return esq; 
}

int main(){
    int casos;
    cin >> casos;

    while(casos){
        int pessoas, ml;
        cin >> pessoas >> ml;

        int b, B, H;
        cin >> b >> B >> H;
        double volume = calculaVolume(b,B,H, H);
        double volumePorPessoa = (double)ml/pessoas;

        double altura = calculaAltura(b, B, H, min(volumePorPessoa, volume), 0, H);
        altura = round(altura*100)/100.0;

        cout << fixed << setprecision(2) << altura << endl;
        casos--;
    }
}
