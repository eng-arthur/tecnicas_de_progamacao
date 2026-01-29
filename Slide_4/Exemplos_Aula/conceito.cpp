#include <iostream>
using namespace std;

int main(){

    float nota;
    cout << "Digite uma nota: ";
    cin >> nota;

    if(nota <=4) cout << "\nInsuficiente";
    else if(nota>4 && nota<7) cout << "\nAbaixo da media";
    else if(nota>=7 && nota<9) cout << "\nAcima da media";
    else if(nota>=9) cout << "\nExecelente";

    return 0;
}