#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long x, y;
    
    while(cin >> x >> y){
        long long res = x-y;
        if(res<0){
            res = -res;
        }
        cout << res << endl;
    }
}