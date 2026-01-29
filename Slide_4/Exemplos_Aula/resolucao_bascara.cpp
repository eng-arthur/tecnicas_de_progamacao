#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float a,b,c,delta;

    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de b: ";
    cin >> b;
    cout << "Digite o valor de c: ";
    cin >> c;

    delta = (pow(b,2)) - ((4*a)*c);

    if(delta>=0){
        if(delta=0){
            cout << "1 Raiz real";
        }else{
            cout << "Duas raizes reais";
        }
    }else{
        cout << "Raizes Imaginarias";
    }

    return 0;
}