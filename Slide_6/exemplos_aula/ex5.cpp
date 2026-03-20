#include <iostream>
#include <cstring>
using namespace std;

void mudar(char palavra[4]);

int main(){

    char vetor[4] = "ABC";

    mudar(vetor);

    cout << vetor << endl;

    return 0;
}

void mudar(char palavra[4]){
    strcpy(palavra,"CBA");
}