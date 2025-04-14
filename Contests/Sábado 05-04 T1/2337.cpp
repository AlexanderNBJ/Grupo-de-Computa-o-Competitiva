#include <bits/stdc++.h>
using namespace std;

int main(){
    long double l;
    cin >> l;

    while(l){
        cout << fixed << setprecision(6) << (l-3)/l << endl;
        cin >> l;
    }
}