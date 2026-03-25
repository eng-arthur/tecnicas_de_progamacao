    #include <iostream>
    using namespace std;

    class Veiculo{
        private:
            int velocidade=100; //Variável encapsulada
        public:
            int getVel();
    };

    int Veiculo::getVel(){
        return velocidade;
    }

    int main(){
        Veiculo v1;

        cout << v1.getVel();
        return 0;
    }