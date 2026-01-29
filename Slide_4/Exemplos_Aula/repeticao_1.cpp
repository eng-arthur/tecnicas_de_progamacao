#include <iostream>
using namespace std;

int main(){

    int a;
    int contador=0;
    cout << "Deseja iniciar o contador?: ";
    cin >> a;

    while(a==1){
        contador++;
        cout << "Deseja continuar contando?: ";
        cin >> a;
    }

    cout << "O valor contado foi: " << contador;

    return 0;
}