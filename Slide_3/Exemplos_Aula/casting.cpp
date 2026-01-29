#include <iostream>
using namespace std;

int main(){

    float a;

    cout << "Digite um valor em ponto flutuante: ";
    cin >> a;

    cout << "\nO valor antes do casting e: " << a;
    cout << "\nO valor obtido apos o casting e: " << int (a);


    return 0;
}