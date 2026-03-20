#include <iostream>
using namespace std;

int main(){

    int idade[10];

    for(int i=0;i<10;i++){
        cout << "Digite a idade do aluno: ";
        cin >> idade[i];
    }

    for(int i=0;i<10;i++){
        cout << "Idade[" << i << "]: " << idade[i] << endl;
    }

    return 0;
}