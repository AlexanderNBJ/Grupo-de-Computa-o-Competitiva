/*
    Nomes:  Alexander Neves Barbosa Junior
            Maurílio Rittershaussen Novaes
*/

#include <iostream>
using namespace std;

void paraBase32(unsigned long x, string& res){
    if(!x){
        return;
    }
    else{
        int carct = x%32;
        x = x/32;
        paraBase32(x, res);
        if(carct < 10){
            res+=to_string(carct);
        }
        else{
            res+= (char) (carct + 55);
        }
    }
}

int main(){
    unsigned long num;
    cin >> num;

    while(true){
        if(!num){
            cout << 0 << endl;
            break;
        }
        string res = "";
        paraBase32(num, res);
        cout << res << endl;
        cin >> num;

    }
}
