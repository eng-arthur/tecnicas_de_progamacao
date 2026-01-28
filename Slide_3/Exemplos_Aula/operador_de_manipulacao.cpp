#include <iostream>
using namespace std;

int main(){

    char a;

    cout << "Digite um caracter: ";
    cin >> a;

    if(a & 0000001){
        cout << "O bit menos significativo e 1";
    }else{
        cout << "O bit menos significativo e 0";
    }

    return 0;
}