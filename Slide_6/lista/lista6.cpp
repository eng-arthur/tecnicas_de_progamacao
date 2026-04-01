#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int menu();
void imprimir(float ordenados[]);
void ordenar(float ordenados[], int f);
void intercambio(float& x, float& y);

class vetor_tri{
private:
    int x;
    int y;
    int z;
public:
    void setX(int xi);
    void setY(int yi);
    void setZ(int zi);
    int getX();
    int getY();
    int getZ();
    void addManual();
    void addAutomatico();
    float magnitude;
    void calcMagnitude();
    vetor_tri();
};

vetor_tri::vetor_tri(){
    x=0;
    y=0;
    z=0;
    cout << "\nObjetos incializados\n";
}

void vetor_tri::setX(int xi){
    x = xi;
}
void vetor_tri::setY(int yi){
    y = yi; 
}
void vetor_tri::setZ(int zi){
    z = zi;
}

int vetor_tri::getX(){
    return x;
}
int vetor_tri::getY(){
    return y;
}
int vetor_tri::getZ(){
    return z;
}

void vetor_tri::addManual(){
    int x;
    int y;
    int z;
    cout << "\nDigite o valor de X: ";
    cin >> x;
    setX(x);
    cout << "\nDigite o valor de Y: ";
    cin >> y;
    setY(y);
    cout << "\nDigite o valor de Z: ";
    cin >> z;
    setZ(z);
}

void vetor_tri::addAutomatico(){
    setX(rand()%11-5);
    setY(rand()%11-5);
    setZ(rand()%11-5);
}

void vetor_tri::calcMagnitude(){
    magnitude = sqrt((pow(x,2))+(pow(y,2))+(pow(z,2)));
    cout << " Magnitude: " << magnitude << endl;
}

int main(){
    srand(time(0));
    int seletor;
    string geracao;
    vetor_tri array[10];
    float ordenados[10];

    while(true){

        seletor = menu();

        switch(seletor){

            case 0:
                return 0;

            case 1:
                cout << "\nDeseja adicionar os valores manualmente ou adicionar através da geracao automática [manual/automatico]: ";
                cin >> geracao;
                if(geracao=="manual"){
                    for(int i=0;i<10;i++){
                        array[i].addManual();
                    }
                }else if(geracao=="automatico"){
                    for(int i=0;i<10;i++){
                        array[i].addAutomatico();
                    }
                }
                continue;

            case 2: 
                for(int i=0;i<10;i++){
                    cout << "\nVetor[" << i << "] de";
                    array[i].calcMagnitude();
                }
                continue;

            case 3:
                for(int i=0;i<10;i++){
                    ordenados[i]=array[i].magnitude;
                }
                ordenar(ordenados,10);
                imprimir(ordenados);
                continue;

            case 4:

                float somX[10];
                float somY[10];
                float somZ[10];
                float subX[10];
                float subY[10];
                float subZ[10];
                float dist[10];

                for(int i=0;i<9;i++){
                    somX[i] = array[i].getX() + array[i+1].getX();
                    somY[i] = array[i].getY() + array[i+1].getY();
                    somZ[i] = array[i].getZ() + array[i+1].getZ();
                }
                for(int i=0;i<9;i++){
                    subX[i] = array[i].getX() - array[i+1].getX();
                    subY[i] = array[i].getY() - array[i+1].getY();
                    subZ[i] = array[i].getZ() - array[i+1].getZ();
                }
                for(int i=0;i<9;i++){
                    dist[i] = sqrt(pow(array[i].getX()-array[i+1].getX(),2) + pow(array[i].getY()-array[i+1].getY(),2) + pow(array[i].getZ()-array[i+1].getZ(),2));
                }

                for(int i=0;i<10;i++){
                    cout << endl;
                    cout << i << " | "<< " Somatorio de X: " << somX[i] << endl;
                    cout << i << " | "<< " Somatorio de Y: " << somY[i] << endl;
                    cout << i << " | "<< " Somatorio de Z: " << somZ[i] << endl;
                    cout << i << " | "<< " Subtracao de X: " << subX[i] << endl;
                    cout << i << " | "<< " Subtracao de Y: " << subY[i] << endl;
                    cout << i << " | "<< " Subtracao de Z: " << subZ[i] << endl;
                    cout << i << " | "<< " Distancia de X: " << dist[i] << endl;
                }
                continue;
        }
    }
return 0;
}

int menu(){
    int opc;
    cout << "\nDigite qual opção deseja selecionar para realizar: \n";
    cout << "1 - Gerar valores Pseudo aleatórios\n";
    cout << "2 - Magnitude\n";
    cout << "3 - Imprimir em ordem crescente\n";
    cout << "4 - Computar e imprimir a soma, a subtração, e a distancia\n";
    cout << "0 - Sair do Aplicativo\n";
    cout << "Opcao: ";
    cin >> opc;
    return opc;
}

void intercambio(float& x, float& y){
    float temp=x;
    x=y;
    y=temp;
}

void imprimir(float ordenados[]){
    for(int i=0;i<10;i++){
        cout << i << " | " << ordenados[i] << endl;
    }
}

void ordenar(float ordenados[], int f){
    for(int i=f;i>0;i--){
        for(int j=0;j<i-1;j++){
            if(ordenados[j]>ordenados[j+1]) intercambio(ordenados[j], ordenados[j+1]);
        }
    }
}
