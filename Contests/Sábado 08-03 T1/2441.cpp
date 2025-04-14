/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas

    JANELA
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int f1,f2,f3;
    cin >> f1 >> f2 >> f3;

    vector<int> v;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f3);
    sort(v.begin(), v.end());

    int area1, area2;
    area1 = max(0, 200-(v[1]-v[0]))*100;
    area2 = max(0, 200-(v[2]-v[1]))*100;

    int areaVentilada = 600*100 - (3*(200*100) -area1 -area2);

    cout << areaVentilada << endl;
    return 0;
}