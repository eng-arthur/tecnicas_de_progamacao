#include <iostream>
using namespace std;

int main(){

    int l,c,n=1;

    cout << "Digite o valor final: ";
    cin >> n;

    for(l=1;l<=n;l++){
        for(c=1;c<=l;c++){
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}