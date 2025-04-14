/*
    Alunos: Alexander Neves Barbosa Junior
            Davi Paulino Laboissiere Dantas
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
using namespace std;

int euclides(int x, int y){
    int r;

    while (x%y > 0){
        r = x%y;
        x = y;
        y = r;
    }

    return y;
}

int mdc(int x, int y, int z){
    int res = euclides(x,y);
    res = euclides(res, z);
    return res;
}

string verifica(int x, int y, int z){
    bool pit = false;
    bool primitiva = false;

    if(x*x == y*y + z*z){
        pit = true;
    }
    else if(y*y == x*x + z*z){
        pit = true;
    }
    else if(z*z == x*x + y*y){
        pit = true;
    }

    if(mdc(x,y,z) == 1){
        primitiva = true;
    }

    if(pit && primitiva){
        return "tripla pitagorica primitiva";
    }
    else if(pit && !primitiva){
        return "tripla pitagorica";
    }
    else{
        return "tripla";
    }
}

int main(){
    int x, y, z;

    while(cin >> x >> y >>z){
        cout << verifica(x,y,z) << endl;
    }
}