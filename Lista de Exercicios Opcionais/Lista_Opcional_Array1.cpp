#include <iostream>
using namespace std;

int main(){
    int tam;
    int busca;
    int a;
    int l,c;
    int x,z;


    int temp,controle=0;
    cout << "Digite o tamanho do array: ";
    cin >> tam;
    controle=tam;

    int array[tam];

    for(int i=0;i<tam;i++){
        cout << endl;
        cout << i << " | ";
        cin >> array[i];
    }

    cout << "\n------------------------------------------------------------------------------------------------\n";

    cout << "\nFaça um codigo que imprima todos os valores negativos da array e seus respectivos indices.\n";

    for(int i=0;i<tam;i++){
        if(array[i]<0)  cout << endl << i << " | " << array[i];
    }

    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout << "\nFaça um codigo que espelhe os elementos da array, ou seja, troca o primeiro pelo ultimo, o segundo pelo penultimo, e assim por diante. Apos isto, imprima a array espelhada na tela.\n";


    if(tam%2==0) a=((tam/2));
    else         a=(tam-1)/2;

    for(int i=0;i<a;i++){

        temp = array[i];
        array[i] = array[(tam-1)-i];
        array[(tam-1)-i] = temp;
    }

    for(int i=0; i<tam;i++){
        cout << array[i] << " ";
    }

    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    cout << "Solicite a um usuario um valor inteiro X e busque se este valor esta entre os elementos da Array. Caso positivo, imprima a posicao do primeiro valor encontrado e troque seu valor na Array para 0. Apos isto, imprima a array na tela." << endl;

    cout << "Escreva qual valor deseja buscar no array: " << endl;
    cin >> busca;
    cout << "\n-------------------------------------------------------------------\n";


    for(int i=0;i<tam;i++){
        if(array[i]==busca){
            cout << "A posicao em que o numero digitado esta: " << i;
            array[i]=0;
            break;
        }
    }

    cout << "\n-------------------------------------------------------------------\n";

    for(int i=0;i<tam;i++){
        cout << endl << endl << i << " | " << array[i];
    }

    cout << "\nCrie uma matriz N x N e preencha todas as linhas da matriz com os N valores dados pelo usuário. Após isto, imprima a array e a matriz na tela.\n";

    cout << "Digite a quantidade de linhas que sua matriz tera: ";
    cin >> l;
    cout << "\nDigite a quantidade de colunas que sua matriz tera: ";
    cin >> c;

    int matriz[l][c];

    for( z=0;z<l;z++){
        for(int x=0;x<c;x++){
            cin >> matriz[z][x];
        }
    }

    for(z=0;z<l;z++){
        for(x=0;x<c;x++){
            cout << matriz[z][x] << " ";
        }
        cout << endl;
    }
}