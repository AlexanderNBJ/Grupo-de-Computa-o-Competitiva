#include <bits/stdc++.h>
using namespace std;

long long fat(long long x){
    long long res = 1;

    while(x){
        res = res * x;
        x = x-1;
    }
    return res;
}

int main(){
    long long a,b;

    while(cin >> a >> b){
        cout << fat(a) + fat(b) << endl;
    }
}