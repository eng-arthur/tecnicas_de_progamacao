#include <iostream>
using namespace std;

int main(){
    int vlr,cont=0;

    cout << "Digite o valor do loop: ";
    cin >> vlr;

    for(cont=0;cont<=vlr;cont++){
        cout << cont << "\n";
    }

    return 0;
}