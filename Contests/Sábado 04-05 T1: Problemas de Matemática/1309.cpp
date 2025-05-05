#include <bits/stdc++.h>
using namespace std;

int main(){
    string dolares, cents;

    while(cin >> dolares >> cents){
        int cont = 0;
        int n = dolares.size();
        int grupo = n%3;
        cout << "$";

        if(grupo > 0){
            cout << dolares.substr(0, grupo);
            if(n > grupo){
                cout << ",";
            }
        }

        for(int i=grupo; i<n; i+=3){
            cout << dolares.substr(i, 3);
            if(i+3<n){
                cout << ",";
            }
        }

        if(cents.size()==1){
            cout << ".0" << cents << endl;
        }
        else{
            cout << "." << cents << endl;
        }

    }
}