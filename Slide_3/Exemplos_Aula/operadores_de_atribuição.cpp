#include <iostream>
using namespace std;

int main(){

    int v,m,d;

    cout << "Digite um valor inteiro: ";
    cin >> v;

    m = v << 1;
    d = v >> 1;

    cout << "\nO valor multiplicado por 2: " << m;
    cout << "\nO valor dividido por 2: " << d;

    return 0;
}