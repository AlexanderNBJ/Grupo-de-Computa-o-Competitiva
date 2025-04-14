/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    SOMA DE FRAÇÕES
*/

#include <iostream>

using namespace std;

int mdc(int a, int b){
    while(b!=0){
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int mmc(int a, int b){
    return (a*b)/mdc(a,b);
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int denom = mmc(b,d);
    int num = ((int)denom/b)*a + ((int)denom/d)*c;
    
    int div = mdc(num, denom);
    num /= div;
    denom /= div;

    cout << num << " " << denom << endl;

    return 0;
}