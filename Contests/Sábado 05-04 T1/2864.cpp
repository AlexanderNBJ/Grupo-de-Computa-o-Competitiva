#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        long double a, b, c;
        cin >> a >> b >> c;

        long double xv = -b/(2*a);
        cout << fixed << setprecision(2) << a*xv*xv +b*xv + c << endl;
    }
}