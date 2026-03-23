#include <iostream>
using namespace std;

int busca(int x[], int n, int TAM);

int main(){

    int x[10]={15, 41, 76, 64, 97, 33, 82, 18, 9, 48};
    int n=0;
    int r;

    cout << "Digite o valor que deseja procurar dentro do array: ";
    cin >> n;

    r = busca(x,n,10);

    if(r== -1) cout << "\nNao foi encontrado o valor digitado dentro do array";
    else cout << "\n O valor digitado foi encontrado e estava no indice: " << r << " do vetor.";

    return 0;
}

int busca(int x[], int n, int TAM){
    enum retorno{FALSE, TRUE}; // NESTE ENUM NOS CRIAMOS QUE O FALSE == 0 E O TRUE == 1 OBS: NÃO HAVIA A NECESSIDADE DE USAR O ENUM, FOI UTILIZADO APENAS COMO CUNHO EDUCATIVO.
    int encontrada = FALSE; //ESPECIFICAMOS QUE O ENCONTRADA == 0.
    int i=0;

    while(!encontrada && i<TAM){
        if(x[i]==n) encontrada=TRUE; //CASO ENCONTREMOS DENTRO DO VETOR NA POSIÇÃO I O VALOR IGUAL A N, O ENCONTRADA RECEBERÁ TRUE QUE EQUIVALE A 1;
        else        i++;
    }

    if(encontrada==TRUE) return i;
    else                 return -1;
}