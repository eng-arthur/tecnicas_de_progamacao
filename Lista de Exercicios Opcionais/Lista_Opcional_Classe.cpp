/*
Crie uma classe que modele um ar-condicionado que tenha funções-membro para ligar/desligar, aumentar e diminuir a temperatura, tendo as seguintes restrições:
1.	A temperatura só poderá ser ajustada caso o ar esteja ligado. 
2.	Sempre que o ar-condicionado for ligado, o valor inicial deverá ser de 21 graus.
3.	A temperatura do ar só pode variar entre 16 e 30 graus.
Após isso, faça um programa que crie um objeto desta classe e que utilize somente ponteiro para acionar as funções do objeto.  
Teste o programa de forma que o usuário possa ligar/desliga o ar, mudar a temperatura, garantindo que os resultados das operações sejam mostradas ao usuário.
*/

#include <iostream>
#include <string>
using namespace std;

class ar_condicionado{
private:

public:
    bool estado;
    int temp;
    void aumentarTemp();
    void diminuirTemp();
    void trocaEstado();
    void imprimir();
    ar_condicionado();
};

ar_condicionado::ar_condicionado(){
    estado=false;
    temp=21;
}

void ar_condicionado::aumentarTemp(){
    if(estado == true)
        if(temp<30)     temp++;
}

void ar_condicionado::diminuirTemp(){
    if(estado == true)
    if(temp>16)temp--;
}

void ar_condicionado::trocaEstado(){
    estado = !estado;
    if(estado == false) temp = 21;

}

void ar_condicionado::imprimir(){
    cout << "\n--------------------\n";
    if(estado==false) cout << "Desligado\n";
    else              cout << "Ligado\n";
    cout << temp << endl;
    cout << "--------------------";
}

int main(){

    char controle;

    ar_condicionado a1;
    ar_condicionado *p;

    p = &a1;

    while(true){
        cin >> controle;
        if(controle == '+') p->aumentarTemp();
        else if(controle == '-') p->diminuirTemp();
        else if(controle == 'l') p->trocaEstado();
        else break;
        p->imprimir();
    }

return 0;
}