#include <iostream>
#include <cmath>
using namespace std;

int main(){

    char a;
    int c,b,l,u;
    int o[6];
    int n;

    cout << "\n";

    //Entrada de valores
    cout << "Digite um caracter: ";
    cin >> a;
    cout << "Digite o valor de n: ";
    cin >> n;

    cout << "\n" << "==================================\n";

    //Mostre na tela se o caracter é letra ou numero.
    if(a>='a' && a<='z' || a>='A' && a<='Z'){
        cout << "O caractere digitado e uma letra";
    }else if(a>='0'&&a<='9'){
        cout << "O caractere digitado e um numero";
    }

    cout << "\n" << "==================================\n";

    //Mostre na tela o valor em binário...
    b = int(a);
    for(c=6;c>=0;c--){
        o[c]=b%2;
        b/=2;
    }
    for(c=0;c<=6;c++){
        cout << o[c];
    }
    
    cout << "\n" << "==================================\n";

    //Mostre na tela se n é par ou impar.
    if(n%2==0){
        cout << "O valor digitado em n e par";
    }else{
        cout << "O valor digitado em n e impar";
    }

    cout << "\n" << "==================================\n";

    //Mostre na tela o valor de f(n)=n²+5n+2.
    cout << "O valor do calculo da expressao: " << ((pow(n,2))+(5*n))+2;

    cout << "\n" << "==================================\n";

    /*Mostre na tela uma semi-pirâmide, como mostrada abaixo, em que sua
    altura seja de acordo como o valor de n dado e o caractere da pirâmide
    seja o valor de a. No exemplo abaixo, a pirâmide é para n = 6 e a = ‘x’.*/
    for(l=1;l<=n;l++){
        for(u=1;u<=l;u++){
            cout << a;
        }
        cout << "\n";
    }

    return 0;
}