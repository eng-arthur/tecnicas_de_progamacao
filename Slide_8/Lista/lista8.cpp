#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int menu();

int main(){
    srand(time(0));
    int opt;

    int n;
    cout << "\nDigite a quantidade de elementos do vetor: ";
    cin >> n;

    float *p = new float[n];

    while(true){

        float *m = new float[1];
        float *t = new float[1];
        *m=0;
        *t=0;
        
        opt = menu();
        switch(opt){
            case 0:{
                return 0;
            }
            case 1:{
                for(int i=0;i<n;i++){
                    p[i]=rand()%101;
                }
                continue;
            }
            case 2:{
                for(int i=0;i<n;i++){
                    p[i]=sin(i);
                }
                continue;
            }
            case 3:{
                for(int i=0;i<n;i++){
                    cout << "\nVet[" << i << "]: ";
                    cin >> p[i];
                }
                continue;
            }
            case 4:{
                *m=0;
                for(int i=0;i<n;i++){
                    *m+=p[i];
                }
                cout << "\nA media dos valores escritos no ponteiro: " << *m/n;
                delete[] m;
                continue;
            }
            case 5:{
                *m=0;
                for(int i=0;i<n;i++){
                    *m+=pow(p[i],2);
                }
                cout << "\nO valor medio quadratico dos valores do vetor: " << sqrt((*m/n));
                delete[] m;
                continue;
            }
            case 6:{
                *m=0;
                *t=0;
                for(int i=0;i<n;i++) *t+=p[i];
                *t/=n;
                for(int i=0;i<n;i++) *m+=pow((p[i]-*t),2);
                *m/=n;
                cout << "\nO valor da variancia: " << *m;
                delete[] t;
                delete[] m;
                continue;
            }
        }
    }
}

int menu(){
    int x;
    cout << "\nDigite a opção que deseja selecionar no menu:\n";
    cout << "\n1 - Inicializcao de elementos Pseudo-Aleatorios";
    cout << "\n2 - Inicializar os elementos do vetor com o Sen do iesimo elemento";
    cout << "\n3 - Inicialize os elementos do vetor com um valor constante do usuario";
    cout << "\n4 - Computar e Imprimir os valores medios do vetor desalocando a memoria";
    cout << "\n5 - Computar e imprimir o valor medio quadratico dos valores do vetor";
    cout << "\n6 - Compute e imprima o valor de variancia dos valores do vetor";
    cout << "\n0 - Sair do programa";
    cout << "\nOpcao: ";
    cin >> x;
    return x;
}