/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mdc(int a, int b){

    while(b){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int mmc(int a, int b){
    return a*b/(mdc(a,b));
}

int main(){
    int n, t;

    while(true){
        cin >> n >> t;

        if(!n && !t){
            break;
        }
        else{
            int tempo = -1;
            int tmp = 1;
            vector<int> tempos(n);
            
            bool naoDa = false;
            for(int i=0; i<n; i++){
                cin >> tempos[i];

                if(t%tempos[i]){
                    naoDa = true;
                }
                tmp = mmc(tmp, tempos[i]);
            }

            if(naoDa){
                cout << "impossivel" << endl;
            }
            else{
                sort(tempos.begin(), tempos.end());

                int aux = 0;
                bool achou = false;

                for(int i=2; i<=t; i++){
                    if(i == tempos[aux]){
                        aux++;
                        continue;
                    }
                    else{
                        if(t%i == 0 && !achou && mmc(i, tmp) == t){
                            tempo = i;
                            achou = true;
                            break;
                        }
                    }
                }

                if(achou){
                    cout << tempo << endl;
                }
                else{
                    cout << "impossivel" << endl;
                }
            }
        }
    }
}