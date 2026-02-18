#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

    int sel,a,b,n;
    int y=0;
    int cont;
    string s="Sim";
    char l1,l2,c;

    while(true){

        cout << "Digite o valor para escolher o menu: ";
        cin >> sel;

        switch(sel){
            case 1:

                cout << "\nDigite a 1 Letra: ";
                cin >> l1;
                cout << "\nDigite a 2 Letra: ";
                cin >> l2;

                cout << "As letras entre " << l1 << " e " << l2 << "sao: ";
                for(c=l1;c<=l2;c++){
                    cout << c;
                }

                cout << "\nDeseja continuar ? ";
                cin >> s;
                if(s=="Sim") continue;
                else break;

            case 2:

                cout << "\nDigite o valor de a: ";
                cin >> a;
                cout << "\nDigite o valor de b: ";
                cin >> b;

                for(cont=1;cont<=b;cont++){
                    y = y + cont+3;
                }
                
                cout << "\nO valor do somatorio: " << y;

                cout << "\nDeseja continuar ? ";
                cin >> s; 
                if(s=="Sim") continue;
                else break;

            case 3:
                
                cout << "Digite o valor de a: ";
                cin >> a;
                cout << "Digite o valor de b: ";
                cin >> b;

                for(cont=a;cont<=b;cont++){
                    cout << sqrt(cont) << "\n";
                }

                cout << "\nDeseja continuar ? ";
                cin >> s;
                if(s=="Sim") continue;
                else break;

            case 4:

                cout << "Digite o valor que quer mostrar na tela: ";
                cin >> n;

                for(cont=n;cont>=1;cont--){
                    for(cont2=cont;cont>=1;cont2--){
                        cout << cont2;
                    }
                    cout << "\n";
                }

            default:
                continue;
        }
        break;
    }

    return 0;
}









/*Condição de pergunta

            cout << "\nDeseja continuar ? ";
            cin >> s;
            if(s=="Sim") continue;
            else break;


*/