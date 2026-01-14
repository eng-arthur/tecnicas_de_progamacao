#include <iostream>
using namespace std;

int main(){

    int n,p,cont=0;

    cout << "Digite o valor de que ira somar: ";
    cin >> n;
    cout << "Digite o valor de parada: ";
    cin >> p;

    for(cont=1;cont<=p;cont= cont+n){
        cout << cont << "\n";
    }
return 0;
}