#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        long double l;
        cin >> l;

        long double res = l*l*sqrtl(25 + 10*sqrtl(5))/4;

        cout << fixed << setprecision(3) << res << endl;

    }
}