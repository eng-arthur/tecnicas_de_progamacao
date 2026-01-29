#include <iostream>
using namespace std;
int main(){
    float nota;
    cout << "Digite a nota do aluno" << endl;
    cin >> nota;

    if(nota>=9.5){
        cout << "Excelente";
    }else if (nota >= 7){
        cout << "Aprovado" << endl;
    }else{
        cout << "Não aprovado" << endl;
            if (nota > 4)
            cout << "Final" << endl;
            if (nota <= 4)
            cout << "Reprovado" << endl;
    }

    return 0;
}
