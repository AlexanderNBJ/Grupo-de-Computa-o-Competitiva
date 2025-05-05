/*
    Aluno: Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int count = 1, num;

    while(cin >> num, num){
        cout << "Teste " << count << endl;

        int qtde50 = 0, qtde10 = 0, qtde5 = 0, qtde1 = 0;

        while(num >= 50){
            num -=50;
            qtde50++;
        }
        while(num >= 10){
            num -=10;
            qtde10++;
        }
        while(num >= 5){
            num -=5;
            qtde5++;
        }
        while(num >= 1){
            num -=1;
            qtde1++;
        }

        cout << qtde50 << " " << qtde10 << " " << qtde5 << " " << qtde1 << endl << endl;
        count++;
    }
}
