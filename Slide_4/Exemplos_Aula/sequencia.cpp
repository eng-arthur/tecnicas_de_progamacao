#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float x;

    cout << "Digite um valor de ponto flutuante: ";
    cin >> x;

    cout << "O valor da operacao x²+x+1: " << (pow(x,2))+x+1;

    return 0;
}