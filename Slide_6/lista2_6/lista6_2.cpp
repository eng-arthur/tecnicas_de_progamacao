#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int menu();
void ordenamento(float a[], int n);
void intercambio(float& x, float& y);
void impOrd(float o[]);

class vetorTri{
private:
    int x;
    int y;
    int z;
public:
    double mag;
    void setX(int a);
    void setY(int b);
    void setZ(int c);

    int getX();
    int getY();
    int getZ();

    void calcMag();
    void setarVetores();
};

//Setando valores

void vetorTri::setX(int a){
    x=a;
}
void vetorTri::setY(int b){
    y=b;
}
void vetorTri::setZ(int c){
    z=c;
}

// Getando valores

int vetorTri::getX(){
    return x;
}
int vetorTri::getY(){
    return y;
}
int vetorTri::getZ(){
    return z;
}

// Setar valores no vetor manual

void vetorTri::setarVetores(){
    cout << "\nX: ";
    cin >> x;
    cout << "\nY: ";
    cin >> y;
    cout << "\nZ: ";
    cin >> z;
}

// Calculando a magnitude

void vetorTri::calcMag(){
    mag = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}



int main(){
    srand(time(0));
    int opt;
    string maneira;
    vetorTri vet[10];
    float mudanca[10];

    while(true){
        opt = menu();
        switch(opt){
            case 0:{
                return 0;
            }
            case 1:{
                cin.ignore();
                cout << "\nDeseja preencher os vetores de qual maneira? [automatico/manual] ";
                getline(cin,maneira);
                if(maneira=="manual"){
                    for(int i=0;i<9;i++){
                        cout << "\n========Setando os valores do [" << i << "] objeto.================\n";
                        vet[i].setarVetores();
                    }
                }else if(maneira=="automatico"){
                        for(int i=0;i<9;i++){
                            cout << "\nValores do vetor [" << i << "] randomizados setados";
                            vet[i].setX(rand()%11-5);
                            vet[i].setY(rand()%11-5);
                            vet[i].setZ(rand()%11-5);
                        }
                }
                continue;
            }
            case 2:{
                for(int i=0;i<9;i++){
                    vet[i].calcMag();
                    cout << "A magnitude do vetor[" << i <<"]: " << vet[i].mag << endl;
                }
            }
            case 3:{
                for(int i=0;i<9;i++){
                    mudanca[i]=vet[i].mag;
                }
                ordenamento(mudanca,10);
                for(int i=0;i<9;i++){
                    cout << endl << i << " | " << mudanca[i] << endl;
                };

            continue;
            }
        }
    }
}

int menu(){
    int x;
    cout << "\n\nDigite a opcao que deseja selecionar: ";
    cout << "\n1 - Armazenar os valores nos Vetores";
    cout << "\n2 - Computar e Imprimir a magnitude";
    cout << "\n3 - Imprimir em ordem crescente (Pela magnitude)";
    cout << "\n4 - Computar e imprimir SOMA,SUBTRACAO,DISTANCIA entre os vetores";
    cout << "\n0 - Sair do Programa\n";
    cout << "Opcao: ";
    cin >> x;
    cout << endl;
    return x;
}

void ordenamento(float a[], int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(a[j]>a[j+1]){
                intercambio(a[j],a[j+1]);
            }
        }
    }
}

void intercambio(float& x, float& y){
    float temp=x;
    x=y;
    y=temp;
}

