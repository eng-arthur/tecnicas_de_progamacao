#include <iostream>
using namespace std;

void ordenamento(float x[], int k);
void intercambio (float& x, float& y);
void imprimir(float x[], int n);

int main(){

    float x[10]={25.5, 34.1, 27.6, 15.24, 3.27, 5.14, 6.21, 7.57, 4.61, 5.4};
    imprimir(x,10);
    cout << endl;

    ordenamento(x,10);

    imprimir(x,10);

    return 0;
}

void imprimir(float x[], int n){
    for(int i=0;i<n;i++){
        cout << x[i] << " ";
    }
}

void intercambio (float& x, float& y){
    float temp;
    temp=x;
    x=y;
    y=temp;
}

void ordenamento(float x[], int k){
    for(int i=k;i>0;i--)
        for(int j=0;j<i-1;j++)
            if(x[j] > x[j+1]) intercambio(x[j], x[j+1]);
}