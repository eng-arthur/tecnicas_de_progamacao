    #include <iostream>
    #include <string>
    using namespace std;

    class Veiculo{
    private:
        string tipo;
        int velMax;
    public:
        void setTipo();
        void setvelMax();
        int getvelMax();
        string getTipo();
    };

    void Veiculo::setTipo(){
        cout << "Digite o tipo do veiculo: ";
        cin >> tipo;
    }
    void Veiculo::setvelMax(){
        cout << "Digite a velocidade maxima do  veiculo: ";
        cin >> velMax;
    }
    int Veiculo::getvelMax(){
        return velMax;
    }
    string Veiculo::getTipo(){
        return tipo;
    }

    int main(){
        Veiculo v1;

        v1.setTipo();
        v1.setvelMax();

        cout << v1.getTipo() << endl;
        cout << v1.getvelMax() << endl;
    }