#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int x;
        cin >> x;

        unsigned long long graos = 0;
        for(int i=0; i<x; i++){
            graos = graos + powl(2, i);
        }
        cout <<(unsigned long long) (graos/12000) << " kg" << endl;
    }
}