#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n){
        int corridas = 0;

        while(n>1){
            int grupos = n/3;

            if(n%3 != 0){
                grupos = n/3;
                int resto = n%3;

                if(resto == 1 && grupos >0){
                    grupos--;
                    resto +=3;
                }
                grupos += resto/2;
            }
            corridas += grupos;
            n = grupos;
        }
        cout << corridas << endl;
        cin >> n;
    }
   
}