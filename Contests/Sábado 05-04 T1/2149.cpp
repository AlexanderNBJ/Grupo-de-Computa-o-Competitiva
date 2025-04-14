#include <bits/stdc++.h>
using namespace std;

int main(){
    long long vetor[17];
    vetor[0] = 0;
    vetor[1] = 1;

    for(int i=2; i<17; i++){
        if((i+1)%2 == 0){
            vetor[i] = vetor[i-1]*vetor[i-2];
        }
        else{
            vetor[i] = vetor[i-1]+vetor[i-2];
        }
    }

    int caso;

    while(cin >> caso){
        cout << vetor[caso-1] << endl;
    }


}