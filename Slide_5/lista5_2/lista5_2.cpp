#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int menu();

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
    void setNome(string n);
    void setIdade(int id);
    void setCpf(string cp);
    void setEstado(string est);
    void setRenda(double r);
    void setAltura(double a);
    void setPeso(double p);
    void Impressao();

    string getNome();
    int getIdade();
    string getCpf();
    string getEstado();
    double getRenda();
    double getAltura();
    double getPeso();

    void Cadastramento();
    Pessoa();
    ~Pessoa();
};

//Setando os valores

void Pessoa::setNome(string n){
    nome_completo=n;
}
void Pessoa::setIdade(int id){
    idade=id;
}
void Pessoa::setCpf(string cp){
    cpf=cp;
}
void Pessoa::setEstado(string est){
    estado_civil=est;
}
void Pessoa::setRenda(double r){
    renda_mensal=r;
}
void Pessoa::setAltura(double a){
    altura=a;
}
void Pessoa::setPeso(double p){
    peso=p;
}

//Getando os valores

string Pessoa::getNome(){
    return nome_completo;
}
int Pessoa::getIdade(){
    return idade;
}
string Pessoa::getCpf(){
    return cpf;
}
string Pessoa::getEstado(){
    return estado_civil;
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

//Função contrutora que irá predefinir as variáveis internas.

Pessoa::Pessoa(){
    setNome("initial");
    setIdade(0);
    setCpf("00000000000");
    setEstado("initial");
    setRenda(00.0);
    setAltura(00.0);
    setPeso(00.0);
    cout << "\nPessoa Criada\n";
}

//Função que irá destruir o objeto

Pessoa::~Pessoa(){
    cout << "\nObjeto destuido";
}

//Cadastramento

void Pessoa::Cadastramento(){
    cin.ignore();
    cout << "\nDigite o nome da pessoa: ";
    getline(cin,nome_completo);

    while(idade<=0){
        cout << "\nDigite a idade: ";
        cin >> idade;
    }

    cin.ignore();
    cout << "\nDigite o Cpf: ";
    getline(cin,cpf);


    cout << "\nDigite o estado Civil: ";
    getline(cin,estado_civil);

    cout << "\nDigite a renda: ";
    cin >> renda_mensal;

    while(altura<=0){
        cout << "\nDigite a altura: ";
        cin >> altura;
    }

    while(peso<=0){
        cout << "\nDigite o peso: ";
        cin >> peso;
    }

}   

//Impressão das Pessoas

void Pessoa::Impressao(){
    cout << "\n=================================================";
    cout << "\nNome: " << nome_completo;
    cout << "\nIdade: " << idade;
    cout << "\nCpf: " << cpf;
    cout << "\nEstado Civil: " << estado_civil;
    cout << "\nRenda: " << renda_mensal;
    cout << "\nAltura: " << altura;
    cout << "\nPeso: " << peso;
    cout << "\n=================================================";
}

int main(){
    Pessoa P[10];
    int opt;
    int qtdc=0;
    int qtdp;
    double medIdade=0;
    double medRenda=0;
    double medAltura=0;
    double medPeso=0;
    double tdI=0;
    double tdR=0;
    double tdA=0;
    double tdP=0;

    while(true){

        opt = menu();

        switch(opt){



            case 0:{
                return 0;
            }
            case 1:{
                cout << "\nQuantas pessoas deseja cadastrar: ";
                cin >> qtdp;

                for(int i=qtdc;i<=qtdc+qtdp-1;i++){
                    P[i].Cadastramento();
                }
                qtdc+=qtdp;
                continue;
            }
            case 2:{
                for(int i=0;i<=qtdc-1;i++){
                    P[i].Impressao();
                }
                continue;
            }
            case 3: {
                cout << "\n================MEDIAS==============\n";
                for(int i=0;i<=qtdc-1;i++) medIdade=(medIdade+P[i].getIdade())/qtdc;
                cout << "O valor medio das idades: " << medIdade << endl;

                for(int i=0;i<=qtdc-1;i++) medRenda=(medRenda+P[i].getRenda())/qtdc;
                cout << "O valor medio das rendas: " << medRenda << endl;

                for(int i=0;i<=qtdc-1;i++) medAltura=(medAltura+P[i].getAltura())/qtdc;
                cout << "O valor medio das alturas: " << medAltura << endl;

                for(int i=0;i<=qtdc-1;i++) medPeso=(medPeso+P[i].getPeso())/qtdc;
                cout << "O valor medio das pesos: " << medPeso << endl;

                cout << "\n============DesviosPadroes============\n";
                for(int i=0;i<=qtdc-1;i++) tdI+=pow((P[i].getIdade()-medIdade)/qtdc,2);
                cout << "\nO desvio padrao da idade: " << sqrt(tdI);

                for(int i=0;i<=qtdc-1;i++) tdR+=pow((P[i].getRenda()-medRenda)/qtdc,2);
                cout << "\nO desvio padrao da renda: " << sqrt(tdR);

                for(int i=0;i<=qtdc-1;i++) tdA+=pow((P[i].getAltura()-medAltura)/qtdc,2);
                cout << "\nO desvio padrao da altura: " << sqrt(tdA);

                for(int i=0;i<=qtdc-1;i++) tdP+=pow((P[i].getPeso()-medPeso)/qtdc,2);
                cout << "\nO desvio padrao do peso: " << sqrt(tdP);

                continue;
            }
            case 4:{
                for(int i=0;i<=qtdc-1;i++){
                    cout << "\n=================IMC===================";
                    cout << "\nNome: " << P[i].getNome();
                    cout << "IMC: " << P[i].getPeso()/pow(P[i].getAltura(),2);
                    if(P[i].getPeso()/pow(P[i].getAltura(),2)<=18.5) cout << "\nAbaixo do Peso!";
                    else if(P[i].getPeso()/pow(P[i].getAltura(),2)>18.5 && P[i].getPeso()/pow(P[i].getAltura(),2)<=24.9) cout << "\nPeso Normal";
                    else if(P[i].getPeso()/pow(P[i].getAltura(),2)>=25.0 && P[i].getPeso()/pow(P[i].getAltura(),2)<=29.9) cout << "\nSobrepeso!";
                    else if(P[i].getPeso()/pow(P[i].getAltura(),2)>=30) cout << "\nObsidade";
                }
            }
        }

    }

return 0;
}

int menu(){
    int x;
    cout << "\nDigite o valor que deseja selecionar no menu:\n";
    cout << "\n1 - Para criar os usuários\n";
    cout << "\n2 - Qual o usuario que deseja acessar seus dados\n";
    cout << "\n3 - Media das idades e Desvio Padrao\n";
    cout << "\n4 - IMC dos Usuarios\n";
    cout << "\n0 - Fechar o programa\n";
    cout << "Opcao: ";
    cin >> x;
    return x;
}