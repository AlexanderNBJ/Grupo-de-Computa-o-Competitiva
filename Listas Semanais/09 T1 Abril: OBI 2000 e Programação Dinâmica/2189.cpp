/*
    Aluno: Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int count = 1, num;

    while(cin >> num, num){
        vector<int> ingressos(num);
        int ganhador;

        for(int i=0; i<num; i++){
            cin >> ingressos[i];
            if(ingressos[i]==i+1){
                ganhador = i+1;
            }
        }
        cout << "Teste " << count << endl;
        cout << ganhador << endl << endl;
        count++;
    }
}
