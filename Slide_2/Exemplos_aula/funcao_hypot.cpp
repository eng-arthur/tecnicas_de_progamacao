#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a,b;

    cout << "Digite o valor do cateto: ";
    cin >> a;
    cout << "Digite outro valor do cateto: ";
    cin >> b;

    cout << "O valor da hipotenusa: " << hypot(a,b);

return 0;
}