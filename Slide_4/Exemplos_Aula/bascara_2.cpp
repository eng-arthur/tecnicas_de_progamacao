#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){

    float a,b,c,d;
    string z = "Sim";

    while(z=="Sim"){
        //obtenção dos valores
        cout << "Digite o valor de a: ";
        cin >> a;
        cout << "Digite o valor de b: ";
        cin >> b;
        cout << "Digite o valor de c: ";
        cin >> c;

        //calculo de bascara:
        d=(pow(b,2))-((4*a)*c);

        //condição
        if(d>=0){
            
        }
    }

    return 0;
}