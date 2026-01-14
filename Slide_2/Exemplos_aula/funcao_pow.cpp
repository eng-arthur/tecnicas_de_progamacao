#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a;

    cout << "Digite o numero para ver seu quadrado e o seu cubo: ";
    cin >> a;

    cout << "\n" << a << " ao quadrado: " << pow(a,2);
    cout << "\n" << a << " ao cubo: " << pow(a,3);

return 0;
}