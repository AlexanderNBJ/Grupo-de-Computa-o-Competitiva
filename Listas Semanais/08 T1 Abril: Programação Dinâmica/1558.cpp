/*
    Aluno:  Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int num;
    while(cin >> num){
        bool achou = false;

        for(int i=0; i*i <= num; i++){
            int j = num - i*i;
            int jsqrt = sqrt(j);

            if(jsqrt*jsqrt == j){
                achou = true;
                break;
            }
        }
        
        if(achou)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}