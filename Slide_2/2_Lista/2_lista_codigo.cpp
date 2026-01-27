#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.14


int main(){

    char parada='C';
    string nome;
    int idade,cont;
    float r,c1,c2;


    while(parada!='S'){

        //Pedindo para inserir o nome
        cout << "Escreva seu nome completo: ";
        getline(cin,nome);
        cout << nome;
        if(nome == "S"){break;}

        //Pedindo para inserir a idade
        cout << "\nDigite sua idade: ";
        cin >> idade;
        cin.ignore();

        //Analisar todos os valores pares entre 0 e sua idade
        for(cont=0;cont<=idade;cont++){
            if(cont%2 == 0){
                cout << cont << "\n";
            }
        }

        //Imprimir a raiz quadrada de todos os números pares de 1 a 100.
        for(cont=0;cont<=100;cont++){
            if(cont%2==0){
                cout << sqrt(cont) << "\n";
            }
        }

        //Pedido dos valores dos catetos
        cout << "\nInsira o valor do 1° cateto: ";
        cin >> c1;
        cout << "\nInsira o valor do 2° cateto: ";
        cin >> c2;

        //Valor da hipostenusa
        cout << "\n" <<hypot(c1,c2);
        //Perimetro
        cout << "\n" << c1+c2+hypot(c1,c2);
        //Área
        cout << "\n" << (c1*c2)/2;
        //Seno
        cout << "\n" << sin(c1/(hypot(c1,c2)));
        //Cos
        cout << "\n" << cos(c2/(hypot(c1,c2)));
        //Tan
        cout << "\n" << tan(c1/c2);

        //Pedindo o valor do circulo
        cout << "Escreva o valor do raio do circulo: ";
        cin >> r;
        //Diametro
        cout << "O diâmetro do circulo: " << r*2;
        //Perimetro
        cout << "O perimetro do circulo: " << PI*2*r;
        //Área
        cout << "A area do circulo: " << PI*(pow(r,2));
    }
    return  0;
}