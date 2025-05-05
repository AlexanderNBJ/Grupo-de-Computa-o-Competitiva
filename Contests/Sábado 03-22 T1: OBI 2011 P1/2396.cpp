/*
Alexander Neves Barbosa Junior
Maurilio Rittershaussen Novaes
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> tempos;

    for (int i = 0; i < N; i++) {
        int soma = 0;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            soma += x;
        }
        tempos.push_back({soma, i + 1});
    }

    sort(tempos.begin(), tempos.end());

    cout << tempos[0].second << endl;
    cout << tempos[1].second << endl;
    cout << tempos[2].second << endl;

    return 0;
}