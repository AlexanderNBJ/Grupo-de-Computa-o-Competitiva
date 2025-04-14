#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int m, a1, a2, a3;
        cin >> m >> a1 >> a2 >> a3;

        int andar = a1+a2+a3;

        if(andar>1){
            cout << "X" << endl;
        }
        else if(andar == 1){
            if(m){
                cout << "0" << endl;
            }
            else{
                cout << "1" << endl;
            }
        }
        else{
            cout << "0" << endl;
        }
    }
}