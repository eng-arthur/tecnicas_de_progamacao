#include <iostream>
using namespace std;

int main(){

    float nota;
    
    cout << "Digite a nota do aluno\n";
    cin >> nota;

    if(nota>=9.5) cout << "Excelente";
    if(nota>=7 && nota <9.5) cout << "Aprovado";
    if(nota<7){
        cout << "Não aprovado";
        if(nota>4) cout << "\nFinal";
        if(nota<=4) cout << "\nReprovado"; 
    }

    return 0;
}