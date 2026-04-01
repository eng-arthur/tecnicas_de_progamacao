#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int menu();

class MTQ{
private:
    int arrayBi[3][3];
    int determinante;
public:
    void setarArray();
    void detDeter();
    int getDet();
    void printar();
    void setarArrayRand();

};



void MTQ::setarArray(){
    for(int l=0;l<=2;l++){
        for(int c=0;c<=2;c++){
            cout << "\nEscreva o valor da linha[" << l << "] e coluna[" << c << "]: ";
            cin >> arrayBi[l][c];
        }
    }
}

void MTQ::setarArrayRand(){
    for(int l=0;l<=2;l++){
        for(int c=0;c<=2;c++){  
            arrayBi[l][c]= rand()%11-5;
        }
    }
}

void MTQ::printar(){
    for(int l=0;l<=2;l++){
        for(int c=0;c<=2;c++){
            cout << arrayBi[l][c] << " ";
        }
        cout << "\n";
    }
}

int MTQ::getDet(){
    return determinante;
}

void MTQ::detDeter(){
    determinante = ((arrayBi[0][0]*arrayBi[1][1]*arrayBi[2][2])+(arrayBi[0][1]*arrayBi[1][2]*arrayBi[2][0])+(arrayBi[0][2]*arrayBi[1][0]*arrayBi[2][1]))-((arrayBi[2][0]*arrayBi[1][1]*arrayBi[0][2])+(arrayBi[2][1]*arrayBi[1][2]*arrayBi[0][0])+(arrayBi[2][2]*arrayBi[1][0]*arrayBi[0][1]));
}

int somaDet(MTQ *p, MTQ *o);

int main(){
    
    srand(time(0));
    int opt;

    while(true){

        opt = menu();

        switch(opt){
            case 0:
                return 0;

            case 1: {
                MTQ ar1;
                MTQ *p1;
                p1 = &ar1;
                p1->setarArray();
                p1->detDeter();
                //p1->printar();
                cout << p1->getDet();
                continue;
            }

            case 2: {
                MTQ ar2[10];
                MTQ *p2;
                p2=ar2;
                for(int i=0;i<=9;i++){
                    p2->setarArrayRand();
                    p2++;
                }
                p2 = ar2;
                for(int i=0;i<=9;i++){
                    p2->detDeter();
                    cout << "\nA determinante da [" << i << "]: " << p2->getDet();
                    p2++;
                }
                continue;
            }

            case 3: {
                MTQ ar3[2];
                MTQ *p3;
                p3 = ar3;
                for(int i=0;i<=1;i++){
                    p3->setarArray();
                    p3++;
                }
                p3=ar3;
                for(int i=0;i<=1;i++){
                    p3->detDeter();
                    p3++;
                }
                p3=ar3;
                cout << somaDet(p3,p3+1);

                continue;
            }
        }
    }

return 0;
}

int menu(){
    int x;
    cout << "\n\nDigite a opcao que deseja selecionar:\n";
    cout << "1 - Determinante da matriz\n";
    cout << "2 - Determinante de valores pseudo aleatórios\n";
    cout << "3 - Soma dos determinantes dos objetos\n";
    cout << "0 - Sair do programa\n";
    cout << "Opcao: ";
    cin >> x;
    return x;
}

int somaDet(MTQ *p, MTQ *o){
    return p->getDet()+o->getDet();
}