#include <iostream>
using namespace std;

float media(float,float,float);

int main(){

    float a,b,c=0;

    cout << "Digite o primeiro valor: ";
    cin >> a;
    cout << "Digite o segundo valor: ";
    cin >> b;
    cout << "Digite o terceiro valor: ";
    cin >> c;

    cout << media(a,b,c);

return 0;
}

float media(float a, float b, float c){
    return (a+b+c)/3;
}