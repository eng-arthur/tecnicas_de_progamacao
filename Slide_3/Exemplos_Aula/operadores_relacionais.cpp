#include <iostream>
using namespace std;

int main(){

    int Y;
    cout << "Digite o valor da media no aluno: ";
    cin >> Y;

    if(Y<7){
        cout << "Tente novamente, voce consegue";
    }else if(Y>9){
        cout << "Aprovado e Parabens";
    }else{
        cout << "Aprovado";
    }
}