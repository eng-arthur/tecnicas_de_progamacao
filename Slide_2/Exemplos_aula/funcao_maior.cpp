#include <iostream>
using namespace std;

int maior(int,int);

int main(){

    int a,b=0;

    cout << "Digite o primeiro valor: ";
    cin >> a;
    cout << "Digite o segundo valor: ";
    cin >> b;

    cout << maior(a,b);

return 0;
}

int maior(int a, int b){
    int c;
    if(a>b){
        c = a;
    }else{
        c = b;
    }
return c;
}