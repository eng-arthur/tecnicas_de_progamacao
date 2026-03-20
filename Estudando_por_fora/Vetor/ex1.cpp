#include <iostream>
using namespace std;
#define TAM 100

void lerArray(int x[],int& num);
void exibirArray(int y[],int par);

int main(){

    int x[TAM];
    int n;

    lerArray(x,n);
    cout << "O nosso array tem o tamanho de: " << n << endl;
    exibirArray(x,n);

    return 0;
}

void lerArray(int x[],int& num){ //Aqui seria a referência de n, onde ele irá sobrescrever a variável
    for(num=0;num<=TAM;num++){
        cout << "\n" << num << ':';
        cin >> x[num];
        if(x[num]==0)   break;
    }
}

void exibirArray(int y[],int par){
    for(int i=0;i<=par;i++){
        cout << y[i] << endl;;
    }
}   