#include <iostream>
using namespace std;
int main () {
    int contador = 0;
    while (true) {
        contador ++;
        if (contador >=10 && contador<=20)
            continue;
        cout << contador << endl;
    }
    cout << "Fim" << endl;
}