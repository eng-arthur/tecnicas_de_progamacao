#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double mediaIdade,mediaRenda,mediaAltura,mediaPeso=0;
double desvioP,desvioI,desvioA,desvioR=0;

class Pessoa{
private:
    string nome_completo;
    int idade;
    string cpf;
    string estado_civil;
    double renda_mensal;
    double altura;
    double peso;
public:
    Pessoa();
    void Cadastramento();
    void Impressao();
    int getIdade();
    double getRenda();
    double getAltura();
    double getPeso();
    string getNome();
};

Pessoa::Pessoa(){
    nome_completo = "Incial";
    idade = 2;
    cpf = "000.000.000-17";
    estado_civil = "Inicial";
    renda_mensal = 2.50;
    altura = 1.70;
    peso = 50.50;
}

Pessoa::~Pessoa(){
    cout << "\nPessoa Excluida do Banco de dados";
}

void Pessoa::Cadastramento(){
    cout << "\nDigite o nome: ";
    getline(cin, nome_completo);
    while(true){
        cout << "\nDigite a idade: ";
        cin >> idade;
        cin.ignore();
        if(idade<0 || idade>180) cout << "\nIdade Invalida !";
        else break;
    }
    while(true){
        cout << "\nDigite o cpf: ";
        getline(cin,cpf);
        if(cpf.length()!=14) cout << "\nCPF Invalido !";
        else break;
    }
    cout << "\nDigite o estado civil: ";
    getline(cin,estado_civil);
    while(true){
        cout << "\nDigite a renda mensal: ";
        cin >> renda_mensal;
        cin.ignore();
        if(renda_mensal<0) cout << "\nRenda Invalida !";
        else break;
    }   
    while(true){
        cout << "\nDigite a altura: ";
        cin >> altura;
        cin.ignore();
        if(altura<0 or altura>3) cout << "\nAltura Invalida !";
        else break;
    }
    while(true){
        cout << "\nDigite o peso: ";
        cin >> peso;
        cin.ignore();
        if(peso<0) cout << "\nPeso Invalido !";
        else break;
    }
}

void Pessoa::Impressao(){
    cout << "\n------------------------------------------";
    cout << "\nNome: " << nome_completo;
    cout << "\nIdade: " << idade;
    cout << "\nCPF: " << cpf;
    cout << "\nEstado Civil: " << estado_civil;
    cout << "\nRenda Mensal: " << renda_mensal;
    cout << "\nAltura: " << altura;
    cout << "\nPeso: " << peso;
    cout << "\n------------------------------------------";
}

int Pessoa::getIdade(){
    return idade;
}
double Pessoa::getRenda(){
    return renda_mensal;
}
double Pessoa::getAltura(){
    return altura;
}
double Pessoa::getPeso(){
    return peso;
}

string Pessoa::getNome(){
    return nome_completo;
}

bool Return(){
    char cond;
    cout << "\nDeseja retornar ao menu? [s/n] ";
    cin >> cond;
    if(cond=='n') return true;
    else          return false;
}

int Menu(){
    int opt;
    cout << "===========MENU============";
    cout << "\n1 - Cadastramento ";
    cout << "\n2 - Media e Desvio Padrao";
    cout << "\n3 - IMC";
    cout << "\n4 - Ver Pessoas Cadastradas";
    cout << "\n5 - Sair";
    cout << "\n=========================\n";
    cout << "Opcao: ";
    cin >> opt;
    return opt;
}

int main(){

    Pessoa p[10];
    int opt,i,qtd=0;
    char cond;
    
    while(true){
        opt = Menu();
        switch(opt){
            case 1:
                while(true){
                    cout << "Digite a quantidade de pessoas que deseja cadastrar: ";
                    cin >> qtd;
                    cin.ignore();
                    if(qtd<0 || qtd>10) cout << "Quantidade Invalida !";
                    else break;
                }
                for(i=0;i<qtd;i++){
                    p[i].Cadastramento();
                }

                if(Return()) break;
                else         continue;
            
            case 2:

                for(i=0;i<qtd;i++){
                    mediaIdade += p[i].getIdade();
                    mediaRenda += p[i].getRenda();
                    mediaAltura += p[i].getAltura();
                    mediaPeso += p[i].getPeso();
                }

                mediaIdade /= qtd;
                mediaAltura /= qtd;
                mediaPeso /= qtd;
                mediaRenda /= qtd;

                for(i=0;i<qtd;i++){
                    desvioA+= pow(p[i].getAltura()-mediaAltura,2);
                    desvioR+= pow(p[i].getRenda()-mediaRenda,2);
                    desvioI+= pow(p[i].getIdade()-mediaIdade,2);
                    desvioP+= pow(p[i].getPeso()-mediaPeso,2);
                }

                cout << "\n============Medias==============";
                cout << "\nMedia Idade: " << mediaIdade;
                cout << "\nMedia Renda: " << mediaRenda;
                cout << "\nMedia Altura: " << mediaAltura;
                cout << "\nMedia Peso: " << mediaPeso;
                cout << "\n==================================";
                cout << "\n=========Desvios Padroes==========";
                cout << "\nDesvio Idade: " << sqrt((desvioI/qtd));
                cout << "\nDesvio Renda: " << sqrt((desvioR/qtd));
                cout << "\nDesvio Altura: " << sqrt((desvioA/qtd));
                cout << "\nDescio Peso: " << sqrt((desvioP/qtd));
                cout << "\n==================================";

                if(Return()) break;
                else         continue;

            case 3:
            
                double IMC[10];
                for(i=0;i<qtd;i++){
                    IMC[i] = p[i].getPeso()/(pow(p[i].getAltura(),2));
                    cout << IMC[i];
                }
                for(i=0;i<qtd;i++){
                    cout << "\n============================IMC===================================";
                    cout << "\nNome: " << p[i].getNome();
                    cout << "\nIMC: " << IMC[i];
                    if(IMC[i]<18.5) cout << "\nClassificacao: Abaixo do Peso !";
                    else if(IMC[i]>=18.5 && IMC[i]<=24.9) cout << "\nClassificacao: Peso Normal !";
                    else if(IMC[i]>=25.0 && IMC[i]<=29.9) cout << "\nClassificacao: Sobrepeso !";
                    else if(IMC[i]>=30.0 && IMC[i]<=34.9) cout << "\nClassificacao: Obesidade Grau 1 !";
                    else if(IMC[i]>=35.0 && IMC[i]<=39.9) cout << "\nClassificacao: Obesidade Grau 2 !";
                    else if(IMC[i]>=40.0) cout << "\nClassificacao: Obesidade Grau 3 (Morbida) !";  
                    cout << "\n===================================================================";
                }
                if(Return()) break;
                else         continue;

            case 4:

                for(i=0;i<qtd;i++){
                    p[i].Impressao();
                }
                if(Return()) break;
                else         continue;
        }
        break;
    }
}