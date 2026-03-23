    #include <iostream>
    #include <string>
    using namespace std;

    class Aviao{
    public:
        int vel=0;
        int velMax;
        void init(int n);
        string modelo;
    };

    void Aviao::init(int n){
        if(n==1){
            modelo="Jato";
            velMax=800;
        }else if(n==2){
            modelo="Monomotor";
            velMax=500;
        }else if(n==3){
            modelo="Planador";
            velMax=180;
        }
    }

    int main(){
        Aviao av1;
        av1.init(1);
        cout << "O modelo e: " << av1.modelo << " e a velocidade maxima: " << av1.velMax;
    }