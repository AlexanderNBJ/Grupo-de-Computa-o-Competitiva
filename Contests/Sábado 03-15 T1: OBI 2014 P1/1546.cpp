/*
    Alunos: Alexander Neves Barbosa Júnior
            Davi Paulino Laboissiere Dantas
*/

#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int k;
        cin >> k;

        for(int i=0; i<k; i++){
            int cat;
            cin >> cat;

            switch(cat){
                case 1:
                    cout << "Rolien" << endl;
                    break;
                case 2:
                    cout << "Naej" << endl;
                    break;
                case 3:
                    cout << "Elehcim" << endl;
                    break;
                case 4:
                    cout << "Odranoel" << endl;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}