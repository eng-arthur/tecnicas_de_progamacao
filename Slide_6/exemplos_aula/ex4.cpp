#include <iostream>
using namespace std;

int main(){

    int linhas,colunas;
    int cont=0;

    int matriz[3][2];

    for(linhas=0;linhas<=2;linhas++){
        for(colunas=0;colunas<=1;colunas++){
            matriz[linhas][colunas]=cont++;
        }
    }

    for(linhas=0;linhas<=2;linhas++){
        for(colunas=0;colunas<=1;colunas++){
            cout << matriz[linhas][colunas] << " ";
        }
        cout << endl;
    }

    return 0;
}