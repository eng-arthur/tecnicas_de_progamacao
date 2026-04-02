#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    int ano;
public:
    string nome;
    int n_familia;
    string *familia;
    Pessoa(){
        cout << "Nome completo: " << endl;
        getline(cin,nome);
        cout << "Numero de familiares: " << endl;
        cin >> n_familia;
        cin.ignore();
        familia = new string[n_familia];
    };
    ~Pessoa(){
        delete[] familia;
    }
};

int main(){
    Pessoa A,B;
    for(int i=0; i<A.n_familia;i++){
        cout << "Nome do familiar de " << A.nome << " : " << endl;
        getline(cin,A.familia[i]);
    }
    for(int i=0;i<B.n_familia;i++){
        cout << "Nome do familiar de " << B.nome << " : " << endl;
        getline(cin,B.familia[i]);
    }
    for(int i=0; i< A.n_familia; i++){
        cout << "Um familiar de " << A.nome << " eh " << A.familia[i] << endl;
    }
    for(int i=0; i < B.n_familia; i++){
        cout << "Um familiar de " << B.nome << " eh " << B.familia[i] << endl;
    }

    return 0;
}