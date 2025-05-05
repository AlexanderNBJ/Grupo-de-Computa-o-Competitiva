/*
    Aluno:  Alexander Neves Barbosa Junior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, circunferencia, remendo1, remendo2;

    while(cin >> n >> circunferencia >> remendo1 >> remendo2){
        vector<int> furos(n);
        int qtde = INT_MAX;

        for(int i=0; i<n; i++){
            cin >> furos[i];
        }

        sort(furos.begin(), furos.end());
        vector<int> furos2 = furos;

        for(int i=0; i<n; i++){
            furos2.push_back(furos[i]+circunferencia);
        }

        for(int i=0; i<n; i++){
            int j = i+n;
            vector<int> mem(j+1, INT_MAX);
            mem[i] = 0;

            for(int k=i; k<j; k++){
                if(mem[k]==INT_MAX){
                    continue;
                }
                    int l = k;

                    while(l<j && furos2[l] <= furos2[k] + remendo1){
                        l++;
                    }
                    mem[l] = min(mem[l], mem[k]+remendo1);

                    l = k;

                    while(l<j && furos2[l] <= furos2[k] + remendo2){
                        l++;
                    }
                    mem[l] = min(mem[l], mem[k]+remendo2);

            }
            qtde = min(qtde, mem[j]);
        }

        cout << qtde << endl;
    }
}
