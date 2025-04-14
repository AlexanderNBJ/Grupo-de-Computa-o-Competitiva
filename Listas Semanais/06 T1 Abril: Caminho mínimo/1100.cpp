/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <bits/stdc++.h>
using namespace std;

int buscaCaminhoMinimo(string xx, string yy){
    if(xx == yy){
        return 0;
    }

    pair<int, int> inicio   =   {xx[0]-'a',  xx[1]-'1'};
    pair<int, int> final    =   {yy[0]-'a',  yy[1]-'1'};

    bool visitados [8][8];
    memset(visitados, false, sizeof(visitados));

    queue<pair<pair<int, int>, int>> q;

    q.push({inicio, 0});
    visitados[inicio.first][inicio.second] = true;

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    while(!q.empty()){
        auto [pos, mov] = q.front();
        q.pop();

        if(pos == final){
            return mov;
        }

        for(int i=0; i<8; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if((nx>=0 && nx<8 && ny>=0 && ny<8) && !visitados[nx][ny]){
                visitados[nx][ny] = true;
                q.push({{nx, ny}, mov+1});
            }
        }
    }

    return 0;
}

int main(){
    string xx, yy;

    while(cin >> xx >> yy){
        cout << "To get from " << xx << " to " << yy << " takes ";
        cout << buscaCaminhoMinimo(xx, yy) << " knight moves." << endl;
    }
}